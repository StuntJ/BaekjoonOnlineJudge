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

struct pq_data{
    int here;
    int hereL;
    ll cost;

    bool operator < (const pq_data &rhs) const{
        return cost>rhs.cost;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int C,E,D;
    int N;
    cin>>C>>E>>D;
    cin>>N;
    vpi station(N);
    station.push_back({0,1}); //0에서는 기름 풀로 출발 더 못넣음
    for(int i=1;i<=N;i++){
        int x;
        cin>>x;
        station[i].first = station[i-1].first+x;
    }
    for(int i=1;i<=N;i++){
        int x;
        cin>>x;
        station[i].second = x;
    }

    station.push_back({D,0});
    sort(station.begin(),station.end());
    int lim = -1; //lim 미만까지 유효
    for(int i=0;i<station.size();i++){
        if(station[i].first==D){
            lim = i+1;
            break;
        }
    }

    const ll INF = 1e15;
    vvll dp(lim,vll(C+1,INF));
    dp[0][C] = 0;
    for(int i=1;i<lim;i++){
        int dist = station[i].first-station[i-1].first;
        for(int j=0;j+dist*E<=C;j++){
            dp[i][j] = min(dp[i][j],dp[i-1][j+dist*E]);
        }
        int stat = dp[i][0];
        if(i!=lim-1){
            for(int j=1;j<=C;j++){
                dp[i][j] = min(dp[i][j],dp[i][j-1]+station[i].second);
            }
        }
    }

    /* for(int i=0;i<lim;i++){
        for(int j=0;j<=C;j++)
            cout<<(dp[i][j]==INF ? -1 : dp[i][j])<<' ';
        cout<<'\n';
    } */

    ll ans = INF;
    for(int i=0;i<=C;i++) ans = min(ans,dp[lim-1][i]);
    if(ans==INF) cout<<-1;
    else cout<<ans; 
}