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

const ll mod = 1e9+7;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    vll A(N),B(M);
    for(auto &i : A) cin>>i;
    for(auto &i : B) cin>>i;

    bool ex[7];
    for(auto i : A) ex[i%7] = true;
    int cnt = 0;
    for(int i=0;i<7;i++) if(ex[i]) cnt++;
    ll temp[7] = {0,1,2,3,4,5,6};
    ll sum = 0;
    for(auto pl : B){
        bool flag = true;
        for(int i=0;i<7;i++){
            if(!ex[i]) continue;
            if(cnt==1){
                if((temp[i]+pl)%7==0){
                    flag = false;
                    break;
                }
            }
            else{
                if((temp[i]+pl)%7==0){
                    cnt--;
                    ex[i] = false;
                }
            }
        }
        if(flag){
            for(int i=0;i<7;i++) temp[i] += pl;
            sum += pl;
        } 
    }
    vll ans;
    for(auto i : A){
        if(ex[i%7]) ans.emplace_back(i+sum);
    }
    for(auto &i : ans) i%=mod;
    cout<<ans.size()<<'\n';
    for(auto i : ans) cout<<i<<' ';
}