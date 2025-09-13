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

    vector<int> v(50);
    for(auto &i : v) cin>>i;

    int x;
    cin>>x;

    int g;
    for(int i=0;i<50;i++){
        if(x==v[i]){
            g = i+1;
            break;
        }
    }

    if(g<=5) cout<<"A+";
    else if(g<=15) cout<<"A0";
    else if(g<=30) cout<<"B+";
    else if(g<=35) cout<<"B0";
    else if(g<=45) cout<<"C+";
    else if(g<=48) cout<<"C0";
    else if(g<=50) cout<<"F";
}