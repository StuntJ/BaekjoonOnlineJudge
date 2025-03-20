#include <bits/stdc++.h>
#define INF 987654321
#define MAX_N 11

using namespace std;

int adj[MAX_N][MAX_N];
int N,K;

int cal(vector<int> &con)
{
    //cout<<con.size()<<'\n';
    /*for(auto i:con)
        cout<<i<<' ';
    cout<<'\n';*/
    int sum = 0;
    for(int i=0;i<con.size();i++)
    {
        for(int j=i+1;j<con.size();j++)
        {
            sum+=adj[con[i]][con[j]];
        }
    }
    return sum;
}

int solve(int x, int choose, vector<int> &con)
{

    //cout<<"x : "<<x<<'\n';
    if(choose==K) return cal(con);
    if(x==N) return -INF;

    int M = solve(x+1,choose,con);
    con.emplace_back(x);
    M = max(M,solve(x+1,choose+1,con));
    con.pop_back();

    return M;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>K;

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>adj[i][j];

    vector<int> con;
    con.clear();
    cout<<solve(0,0,con);
}
