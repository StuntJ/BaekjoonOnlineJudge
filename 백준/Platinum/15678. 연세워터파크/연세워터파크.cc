#include <iostream>
#include <algorithm>
#include <vector>
#define INF 100000000000001

using namespace std;
typedef long long ll;

int N,D;

struct RMQ
{
    int n;
    vector<ll> rangeMax;

    RMQ()
    {
        n = N;
        rangeMax.assign(n*4,0);
    }

    ll query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        if(right<nodeLeft||nodeRight<left) return -INF;
        if(left<=nodeLeft&&nodeRight<=right) return rangeMax[node];
        int mid = (nodeLeft+nodeRight)/2;
        return rangeMax[node] = max(query(left,right,node*2,nodeLeft,mid),query(left,right,node*2+1,mid+1,nodeRight));
    }

    ll query(int left, int right)
    {
        return query(left,right,1,0,n-1);
    }

    ll update(int index, ll newValue, int node, int nodeLeft, int nodeRight)
    {
        if(index<nodeLeft||nodeRight<index) return rangeMax[node];
        if(nodeLeft==nodeRight) return rangeMax[node] = newValue;
        int mid = (nodeLeft+nodeRight)/2;
        return rangeMax[node] = max(update(index,newValue,node*2,nodeLeft,mid),update(index,newValue,node*2+1,mid+1,nodeRight));
    }

    ll update(int index, ll newValue)
    {
        return update(index,newValue,1,0,n-1);
    }
};

vector<ll> cache;
vector<ll> bridge;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>D;

    bridge.resize(N); //0~N-1
    cache.assign(N,-1);

    for(int i=0;i<N;i++)
        cin>>bridge[i];

    RMQ segmentTree;
    for(int i=0;i<N;i++)
    {
        cache[i] = bridge[i];
        cache[i] = max(cache[i],bridge[i]+segmentTree.query(max(0,i-D),i-1));
        segmentTree.update(i,cache[i]);
    }
    cout<<*max_element(cache.begin(),cache.end());
}
