#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct SQ
{
    int n;
    vector<ll> rangeSum;
    vector<ll> Lazy;

    SQ(const vector<ll> &array)
    {
        int n = array.size();
        rangeSum.resize(n*4);
        Lazy.assign(n*4,0);
        init(array,0,n-1,1);
    }

    ll init(const vector<ll> &array, int left, int right, int node)
    {
        if(left==right) return rangeSum[node] = array[left];
        int mid = (left+right)/2;
        return rangeSum[node] = init(array,left,mid,node*2) + init(array,mid+1,right,node*2+1);
    }

    void lazyUpdate(int node, int left, int right)
    {
        if(Lazy[node]!=0)
        {
            rangeSum[node] = rangeSum[node] + (right-left+1) * Lazy[node];
            if(left!=right)
            {
                Lazy[node*2] = Lazy[node*2] + Lazy[node];
                Lazy[node*2+1] = Lazy[node*2+1] + Lazy[node];
            }
            Lazy[node] = 0;
        }
    }

    ll query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        lazyUpdate(node, nodeLeft, nodeRight);
        if(nodeRight<left || right<nodeLeft) return 0;
        if(left<=nodeLeft && nodeRight<=right) return rangeSum[node];
        int mid = (nodeLeft+nodeRight)/2;
        return query(left,right,node*2,nodeLeft,mid) + query(left,right,node*2+1,mid+1,nodeRight);
    }

    void update(int left, int right, ll val, int node, int nodeLeft, int nodeRight)
    {
        lazyUpdate(node,nodeLeft,nodeRight);
        if(nodeRight<left || right<nodeLeft) return;
        if(left<=nodeLeft && nodeRight<=right)
        {
            rangeSum[node] = rangeSum[node] + (nodeRight-nodeLeft+1) * val;
            if(nodeLeft!=nodeRight)
            {
                Lazy[node*2] += val;
                Lazy[node*2+1] += val;
            }
            return;
        }
        int mid = (nodeLeft+nodeRight)/2;
        update(left,right,val,node*2,nodeLeft,mid);
        update(left,right,val,node*2+1,mid+1,nodeRight);
        rangeSum[node] = rangeSum[node*2] + rangeSum[node*2+1];
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,K;
    cin>>N>>M>>K;
    vector<ll> arr(N);

    for(int i=0;i<N;i++)
        cin>>arr[i];

    SQ segmentTree(arr);

    for(int i=0;i<M+K;i++)
    {
        int order;
        cin>>order;
        if(order==1)
        {
            int left,right;
            ll val;
            cin>>left>>right>>val;
            segmentTree.update(left-1,right-1,val,1,0,N-1);
        }
        else
        {
            int left,right;
            cin>>left>>right;
            cout<<segmentTree.query(left-1,right-1,1,0,N-1)<<'\n';
        }
    }
}
