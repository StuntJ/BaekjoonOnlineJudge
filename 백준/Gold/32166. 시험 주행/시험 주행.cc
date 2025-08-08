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
    cout<<fixed;
    cout.precision(6);

    pair<double,double> px[2][3];
    double dist[3];
    pair<double,double> coord[3];
    pair<int,double> stp[2];
    int rev[3] = {-1,-1,-1};
    int idx = 0;
    int em = -1;
    for(int i=0;i<3;i++){
        double x,y,v;
        cin>>x>>y>>v;
        if(v>0){
            stp[idx] = {i,v};
            rev[i] = idx++;
        } 
        else em = i;
        coord[i] = {x,y};
    }
    int w[3];
    for(int i=0;i<3;i++) cin>>w[i];

    double nd[2];
    for(int i=0;i<2;i++){
        int here = stp[i].first;
        double v = stp[i].second;
        double hereTime = 0.0;

        for(int j=0;j<3;j++){
            double dist = hypot(coord[here].first - coord[(here+1)%3].first, coord[here].second - coord[(here+1)%3].second);
            double prev = hereTime;
            hereTime += dist/v;
            px[i][here] = {prev,hereTime};
            here = (here+1)%3;
        }
        nd[i] = hereTime;
    }

    int core = -1;
    if(stp[0].second<stp[1].second) core = 1;
    else core = 0;

    double extra = 0.0;
    for(int i=0;i<3;i++){
        if(px[core][i].first > px[!core][i].first && px[core][i].second < px[!core][i].second && w[i]==1){
            extra += px[!core][i].second-px[core][i].second;
        }
    }
    for(int i=0;i<3;i++){
        if(rev[i]==-1) cout<<'-'<<'\n';
        else if(rev[i]==core) cout<<nd[rev[i]] + extra<<'\n';
        else cout<<nd[rev[i]]<<'\n';
    }
    
}