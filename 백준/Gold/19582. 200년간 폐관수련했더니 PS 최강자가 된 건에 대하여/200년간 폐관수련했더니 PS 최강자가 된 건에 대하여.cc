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

    vector<pair<ll,ll>> v(N);
    for(auto &i : v) cin>>i.first>>i.second;

    ll sum = 0;
    bool flag = true;
    bool ans = true;
    ll maxi = 0;
    for(int i=0;i<N;i++){
        if(sum>v[i].first){
            if(flag){
                if(sum-maxi<=v[i].first){
                    if(maxi>v[i].second)
                        sum-=maxi;
                    else{
                        maxi = max(maxi,v[i].second);
                        flag = false;
                        continue;
                    }
                }
                else{
                    maxi = max(maxi,v[i].second);
                    flag = false;
                    continue;
                }
                flag = false;
            }
            else{
                ans = false;
                break;
            }
        }
        sum+=v[i].second;
        maxi = max(maxi,v[i].second);
    }
    cout<<(ans ? "Kkeo-eok" : "Zzz");
}