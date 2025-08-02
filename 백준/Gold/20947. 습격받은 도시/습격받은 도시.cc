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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vvc grid(N,vc(N));
    for(auto &i : grid){
        for(auto &j : i)
            cin>>j;
    }

    vvb bomb(N,vb(N));
    for(int i=0;i<N;i++){
        bool fill = false;
        for(int j=0;j<N;j++){
            if(grid[i][j]=='X') fill = false;
            else if(grid[i][j]=='O') fill = true;
            if(!bomb[i][j])
                bomb[i][j] = fill;
        }
        for(int j=N-1;j>=0;j--){
            if(grid[i][j]=='X') fill = false;
            else if(grid[i][j]=='O') fill = true;
            if(!bomb[i][j])
                bomb[i][j] = fill;
        }
    }

    for(int j=0;j<N;j++){
        bool fill = false;
        for(int i=0;i<N;i++){
            if(grid[i][j]=='X') fill = false;
            else if(grid[i][j]=='O') fill = true;
            if(!bomb[i][j]) bomb[i][j] = fill;
        }
        for(int i=N-1;i>=0;i--){
            if(grid[i][j]=='X') fill = false;
            else if(grid[i][j]=='O') fill = true;
            if(!bomb[i][j])
                bomb[i][j] = fill;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j]!='.')
                cout<<grid[i][j];
            else cout<<(bomb[i][j] ? '.' : 'B');
        }
        cout<<'\n';
    }
}