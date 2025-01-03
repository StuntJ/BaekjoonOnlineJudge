#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct RSQ
{
    int n;
    vector<ll> rangeSum;

    RSQ(const vector<ll> &array)
    {
        n = array.size();
        rangeSum.resize(n*4);
        init(array,1,0,n-1);
    }

    ll init(const vector<ll> &array, int node, int nodeLeft, int nodeRight)
    {
        if(nodeLeft==nodeRight)
        {
            if(nodeLeft==0) return rangeSum[node] = array[nodeLeft];
            else return rangeSum[node] = array[nodeLeft] - array[nodeLeft-1];
        }
        int mid = (nodeLeft+nodeRight)/2;
        ll leftSum = init(array,node*2,nodeLeft,mid);
        ll rightSum = init(array,node*2+1,mid+1,nodeRight);
        return rangeSum[node] = leftSum+rightSum;
    }

    ll inQuery(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        if(nodeRight<left || right<nodeLeft) return 0;
        if(left<=nodeLeft&&nodeRight<=right) return rangeSum[node];
        int mid = (nodeLeft+nodeRight)/2;
        return inQuery(left,right,node*2,nodeLeft,mid) + inQuery(left,right,node*2+1,mid+1,nodeRight);
    }

    ll query(int x)
    {
        return inQuery(0,x,1,0,n-1);
    }

    ll inUpdate(int idx, ll val, int node, int nodeLeft, int nodeRight)
    {
        if(idx<nodeLeft || nodeRight<idx) return rangeSum[node];
        if(nodeLeft==nodeRight) return rangeSum[node] += val;
        int mid = (nodeLeft+nodeRight)/2;
        ll leftSum = inUpdate(idx,val,node*2,nodeLeft,mid);
        ll rightSum = inUpdate(idx,val,node*2+1,mid+1,nodeRight);
        return rangeSum[node] = leftSum+rightSum;
    }

    void update(int left, int right, ll val)
    {
        inUpdate(left,val,1,0,n-1);
        if(right<n-1) inUpdate(right+1,-val,1,0,n-1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<ll> A(N);

    for(int i=0;i<N;i++)
        cin>>A[i];

    RSQ segTree(A);

    int M;
    cin>>M;

    while(M--)
    {
        int order;
        cin>>order;
        if(order==1)
        {
            int i,j;
            ll k;
            cin>>i>>j>>k;
            segTree.update(i-1,j-1,k);
        }
        else
        {
            int x;
            cin>>x;
            cout<<segTree.query(x-1)<<'\n';
        }
    }
}
