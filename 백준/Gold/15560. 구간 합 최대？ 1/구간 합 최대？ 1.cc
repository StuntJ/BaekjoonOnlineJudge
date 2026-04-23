#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int U,V;

struct st_data
{
    int leftMax;
    int rightMax;
    int midMax;
    int sum;
};

struct RMQ
{
    int n;
    vector<st_data> rangeVal;

    RMQ(const vector<st_data> &array)
    {
        n = array.size();
        rangeVal.resize(n*4);
        init(array,0,n-1,1);
    }

    st_data merge(st_data &left, st_data &right)
    {
        st_data here;
        here.leftMax = max(left.leftMax, left.sum + right.leftMax);
        here.rightMax = max(right.rightMax, right.sum + left.rightMax);
        here.midMax = max(left.midMax,max(right.midMax,left.rightMax+right.leftMax));
        here.sum = (left.sum+right.sum);
        return here;
    }

    st_data init(const vector<st_data> &array, int nodeLeft, int nodeRight, int node)
    {
        if(nodeLeft==nodeRight) return rangeVal[node] = array[nodeLeft];
        int mid = (nodeLeft+nodeRight)/2;
        st_data leftVal = init(array,nodeLeft,mid,node*2);
        st_data rightVal = init(array,mid+1,nodeRight,node*2+1);
        return rangeVal[node] = merge(leftVal,rightVal);
    }

    st_data one = {-INF,-INF,-INF,0};
    st_data query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        if(nodeRight<left || right<nodeLeft) return one;
        if(left<=nodeLeft && nodeRight<=right) return rangeVal[node];
        int mid = (nodeLeft+nodeRight)/2;
        st_data leftData = query(left,right,node*2,nodeLeft,mid);
        st_data rightData = query(left,right,node*2+1,mid+1,nodeRight);
        return merge(leftData,rightData);
    }

    st_data update(int idx, st_data val, int node, int nodeLeft, int nodeRight)
    {
        if(idx<nodeLeft || nodeRight<idx) return rangeVal[node];
        if(nodeLeft==nodeRight) return rangeVal[node] = val;
        int mid = (nodeLeft+nodeRight)/2;
        st_data leftData = update(idx,val,node*2,nodeLeft,mid);
        st_data rightData = update(idx,val,node*2+1,mid+1,nodeRight);
        return rangeVal[node] = merge(leftData,rightData);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,Q;
    cin>>N>>Q>>U>>V;

    vector<st_data> arr(N);
    for(int i=0;i<N;i++)
    {
        int v;
        cin>>v;
        int s = U*v+V;
        arr[i] = {s,s,s,s};
    }

    RMQ segTree(arr);

    for(int i=0;i<Q;i++)
    {
        int order,A,B;
        cin>>order>>A>>B;
        if(order==0)
        {
            cout<<segTree.query(A-1,B-1,1,0,N-1).midMax-V<<'\n';
        }
        else
        {
            int s = U*B+V;
            st_data d = {s,s,s,s};
            segTree.update(A-1,d,1,0,N-1);
        }
    }
}
