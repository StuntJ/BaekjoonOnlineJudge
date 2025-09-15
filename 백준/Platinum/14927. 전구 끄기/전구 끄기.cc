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

    vi v(N);
    for(int i=0;i<N;i++){
        int tot = 0;
        for(int j=0;j<N;j++){
            int x;
            cin>>x;
            if(x) tot += (1<<j);
        }
        v[i] = tot;
    }

    const int INF = 1e9;
    int ans = INF;

    for(int ch=0;ch<(1<<N);ch++){
        int temp = __builtin_popcount(ch);
        int fi = v[0];
        int se = v[1];
        for(int i=0;i<N;i++){
            if(ch&(1<<i)){
                if(i-1>=0) fi^=(1<<(i-1));
                if(i+1<N) fi^=(1<<(i+1));
                fi^=(1<<i);
                se^=(1<<i);
            }
        }

        for(int i=1;i<N-1;i++){
            int th = v[i+1];
            for(int j=0;j<N;j++){
                if(fi&(1<<j)){
                    temp++;
                    if(j-1>=0) se^=(1<<(j-1));
                    if(j+1<N) se^=(1<<(j+1));
                    se^=(1<<j);
                    th^=(1<<j);
                }
            }
            fi = se;
            se = th;
        }
        for(int i=0;i<N;i++){
            if(fi&(1<<i)){
                temp++;
                if(i-1>=0) se^=(1<<(i-1));
                if(i+1<N) se^=(1<<(i+1));
                se^=(1<<i);
            }
        }
        if(se==0) ans = min(ans,temp);
    }
    cout<<(ans==INF ? -1 : ans);
}