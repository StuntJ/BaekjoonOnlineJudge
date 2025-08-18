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
const ll mod = 998244353;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin>>N;
    vll A(N);
    for(auto &i : A) cin>>i;

    ll ans1 = 0;
    for(int i=0;i<30;i++){
        vll continA;
        ll st = 0;
        for(int j=0;j<N;j++){
            bool on = (A[j]&(1LL<<i));
            if(on) st++;
            else{
                if(st) continA.push_back(st); 
                st = 0;
            }
        }
        if(st) continA.push_back(st);
        ll temp = 0;
        for(auto L : continA){
            temp += L + L*(L-1)/2;
            temp%=mod;
        }
        ans1 += temp*(1LL<<i)%mod;
        ans1 %= mod;
    }

    ll ans2 = 0;
    for(int i=0;i<30;i++){
        vll continA;
        ll temp = N*(N+1)/2;
        ll st = 0;
        for(int j=0;j<N;j++){
            bool on = (A[j]&(1LL<<i));
            if(!on) st++;
            else{
                if(st) continA.push_back(st); 
                st = 0;
            }
        }
        if(st) continA.push_back(st);
        for(auto L : continA){
            temp -= L+L*(L-1)/2;
        }
        //cout<<temp<<'\n';
        temp%=mod;
        ans2 += temp*(1LL<<i)%mod;
        ans2 %= mod;
    }

    A.insert(A.begin(),0);
    vll pXor(N+1);
    for(int i=1;i<=N;i++)
        pXor[i] = pXor[i-1]^A[i];

    ll ans3 = 0;
    for(int i=0;i<30;i++){
        ll num0 = 0;
        ll num1 = 0;
        for(int j=0;j<=N;j++){
            if((pXor[j]&(1LL<<i))) num1++;
            else num0++;
        }
        ll temp = (1LL<<i)*num0%mod;
        temp *= num1;
        temp%=mod;
        ans3 += temp;
        ans3%=mod;
    }
    cout<<ans1<<' '<<ans2<<' '<<ans3;
}