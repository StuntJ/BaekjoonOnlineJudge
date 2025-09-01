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

    int T;
    cin>>T;

    vi dp(1000001);
    int idx = 2;
    int four = 0;
    while(true){
        dp[idx++] = 2;
        if(idx>1000000) break;
        for(int i=0;i<four;i++){
            dp[idx++] = 4;
            if(idx>1000000) break;
        } 
        dp[idx++] = 2;
        if(idx>1000000) break;
        for(int i=0;i<=four;i++){
            dp[idx++] = 4;
            if(idx>1000000) break;
        }
        four++;
    }
    /* for(int i=0;i<=100;i++) cout<<dp[i]<<' ';
    cout<<'\n'; */
    for(int i=0;i<1000000;i++){
        dp[i+1] += dp[i];
    }

    while(T--)
    {
        int N;
        cin>>N;
        int orN = N;

        N--;
        int row = 1;
        int col = 1;
        int st = 0;
        while(true){
            if(row*col>N) break;
            st += dp[row*col]+row*col*2;
            N-=row*col;
            row++;

            if(row*col>N) break;
            st += dp[row*col]+row*col*2;
            N-=row*col;
            col++;

            if(row*col>N) break;
            st += dp[row*col]+row*col*2;
            N-=row*col;
        }
        if(N) st += dp[N]+N*2;
        cout<<6*orN-st<<'\n';
    }
}