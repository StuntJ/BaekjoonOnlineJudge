#include <bits/stdc++.h>
#define INF 100000001

using namespace std;

struct st_data
{
    int val;
    int leftSum;
    int rightSum;
    int tot;
};

struct RMQ
{
    int n;
    vector<st_data> rangeMsum;

    RMQ(const vector<st_data> &array)
    {
        n = array.size();
        rangeMsum.resize(n*4);
        init(array,1,0,n-1);
    }

    st_data merge(st_data &a, st_data &b)
    {
        st_data res;
        res.leftSum = max(a.leftSum,a.tot+b.leftSum);
        res.rightSum = max(b.rightSum,b.tot+a.rightSum);
        res.val = max(a.rightSum+b.leftSum,max(a.val,b.val));
        res.tot = a.tot+b.tot;
        return res;
    }

    st_data init(const vector<st_data> &array, int node, int nodeLeft, int nodeRight)
    {
        if(nodeLeft==nodeRight) return rangeMsum[node] = array[nodeLeft];
        int mid = (nodeLeft+nodeRight)/2;
        st_data leftSum = init(array,node*2,nodeLeft,mid);
        st_data rightSum = init(array,node*2+1,mid+1,nodeRight);
        return rangeMsum[node] = merge(leftSum,rightSum);
    }

    st_data one = {-INF,-INF,-INF,0};
    st_data query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        if(nodeRight<left || right<nodeLeft) return one;
        if(left<=nodeLeft&&nodeRight<=right) return rangeMsum[node];
        int mid = (nodeLeft+nodeRight)/2;
        st_data leftSum = query(left,right,node*2,nodeLeft,mid);
        st_data rightSum = query(left,right,node*2+1,mid+1,nodeRight);
        return merge(leftSum,rightSum);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<st_data> arr(N);

    for(int i=0;i<N;i++)
    {
        int x;
        cin>>x;
        arr[i] = {x,x,x,x};
    }

    RMQ segTree(arr);

    int M;
    cin>>M;

    while(M--)
    {
        int i,j;
        cin>>i>>j;
        cout<<segTree.query(i-1,j-1,1,0,N-1).val<<'\n';
    }
}
