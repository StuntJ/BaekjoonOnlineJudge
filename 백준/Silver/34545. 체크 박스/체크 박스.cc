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

    vi v1(N);
    vi v2(N);

    for(auto &i : v1) cin>>i;
    for(auto &j : v2) cin>>j;

    bool isAllCheck = true;
    for(int i=0;i<N;i++){
        if(!v1[i]){
            isAllCheck = false;
            break;
        }
    } 

    int r1 = 1, r2 = 1 + !isAllCheck, r3 = 0;

    for(int i=0;i<N;i++) if(!v2[i]) r1++;
    for(int i=0;i<N;i++) if(v2[i]) r2++;
    for(int i=0;i<N;i++){
        if(v2[i]!=v1[i]) r3++;
    }
    cout<<min(min(r1,r2),r3);
}