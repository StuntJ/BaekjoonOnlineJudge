#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<vector<pi>> vvpi;
typedef vector<vector<vector<pi>>> vvvpi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<long double> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

const int MAX_N = 10020;
int grid[MAX_N][MAX_N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;
    while(T--)
    {
        for(int i=0;i<MAX_N;i++) for(int j=0;j<MAX_N;j++) grid[i][j] = 0;
        int N;
        cin>>N;

        for(int i=0;i<N;i++){
            int x,y;
            cin>>x>>y;

            grid[x][y] += 1;
            grid[x+11][y] += -1;
            grid[x][y+11] += -1;
            grid[x+11][y+11] += 1;
        }

        int M = 0;
        for(int i=0;i<MAX_N;i++){
            for(int j=1;j<MAX_N;j++){
                grid[i][j] += grid[i][j-1];
            }
        }

        for(int j=0;j<MAX_N;j++){
            for(int i=1;i<MAX_N;i++){
                grid[i][j] += grid[i-1][j];
            }
        }
        
        for(int i=0;i<MAX_N;i++)
            for(int j=0;j<MAX_N;j++)
                M = max(M,grid[i][j]);
        
        cout<<M<<'\n';
    }
}