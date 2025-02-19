#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#define ROOT 1

using namespace std;

typedef struct RMQ
{
    int n;
    vector<int> rangeMin;

    RMQ(const vector<int> &array)
    {
        n = array.size();
        rangeMin.resize(n*4);
        init(array,0,n-1,1);
    }

    int init(const vector<int> &array,int left,int right,int node)
    {
        if(left==right) return rangeMin[node] = array[left];
        int mid = (left+right)/2;
        int leftMin = init(array,left,mid,node*2);
        int rightMin = init(array,mid+1,right,node*2+1);
        return rangeMin[node] = min(leftMin,rightMin);
    }

    int MAX_INT = numeric_limits<int>::max();
    int query(int left,int right,int node,int nodeLeft,int nodeRight)
    {
        if(right<nodeLeft||nodeRight<left) return MAX_INT;
        if(left<=nodeLeft&&nodeRight<=right) return rangeMin[node];
        int mid = (nodeLeft+nodeRight)/2;
        return min(query(left,right,node*2,nodeLeft,mid),query(left,right,node*2+1,mid+1,nodeRight));
    }

    int query(int left,int right)
    {
        return query(left,right,1,0,n-1);
    }
};

int N;
vector<int> inDegree;
vector<vector<int>> tree;
queue<pair<int,int>> q;
vector<int> segmentArray;
vector<int> convertToOriginal;
vector<int> convertToNewIndex;
vector<int> locInTrip;
int vertexCount = 1;

void traverse(int here)
{
    convertToNewIndex[here] = vertexCount;
    convertToOriginal[vertexCount] = here;
    vertexCount++;

    locInTrip[convertToNewIndex[here]] = segmentArray.size();
    segmentArray.emplace_back(convertToNewIndex[here]);
    for(int i=0;i<tree[here].size();i++)
    {
        int there = tree[here][i];
        traverse(there);
        segmentArray.emplace_back(convertToNewIndex[here]);
    }
}

void init()
{
    convertToNewIndex.resize(N+1);
    convertToOriginal.resize(N+1);
    locInTrip.resize(N+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    inDegree.assign(N+1,0);
    tree.resize(N+1);

    for(int i=0;i<N-1;i++)
    {
        int a,b;
        cin>>a>>b;

        if(a==ROOT)
        {
            tree[a].emplace_back(b);
            inDegree[b]++;
        }
        else if(b==ROOT)
        {
            tree[b].emplace_back(a);
            inDegree[a]++;
        }
        else if(inDegree[a]!=0)
        {
            tree[a].emplace_back(b);
            inDegree[b]++;
        }
        else if(inDegree[b]!=0)
        {
            tree[b].emplace_back(a);
            inDegree[a]++;
        }
        else q.push(make_pair(a,b));

}
    while(!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        if(a==ROOT)
        {
            tree[a].emplace_back(b);
            inDegree[b]++;
        }
        else if(b==ROOT)
        {
            tree[b].emplace_back(a);
            inDegree[a]++;
        }
        else if(inDegree[a]!=0)
        {
            tree[a].emplace_back(b);
            inDegree[b]++;
        }
        else if(inDegree[b]!=0)
        {
            tree[b].emplace_back(a);
            inDegree[a]++;
        }
        else q.push(make_pair(a,b));

    }

    init();
    traverse(ROOT);
    RMQ segmentTree(segmentArray);

    int M;
    cin>>M;

    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;

        int newa = convertToNewIndex[a];
        int newb = convertToNewIndex[b];
        int locnewa = locInTrip[newa];
        int locnewb = locInTrip[newb];
        if(locnewa>locnewb) swap(locnewa,locnewb);
        int ans = segmentTree.query(locnewa,locnewb);
        cout<<convertToOriginal[ans]<<'\n';
    }
}
