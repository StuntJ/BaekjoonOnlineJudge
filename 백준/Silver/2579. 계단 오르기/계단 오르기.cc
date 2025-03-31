#include <iostream>
#include <vector>

using namespace std;

int stair(int n,int contin, vector<vector<int>> &cache,const vector<int> score)
{
    int &ret = cache[n][contin];
    if(ret!=-1) return ret;
    if(n==0) return ret = 0;
    if(n==1) return ret = score[n];
    if(contin==0) return ret = score[n] + max(stair(n-1,1,cache,score),stair(n-2,0,cache,score));
    if(contin) return ret = score[n] + stair(n-2,0,cache,score);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> score(N+1,0);
    vector<vector<int>> cache(N+1,vector<int>(2,-1));

    for(int i=1;i<=N;i++)
        cin>>score[i];

    cout<<stair(N,0,cache,score);
}
