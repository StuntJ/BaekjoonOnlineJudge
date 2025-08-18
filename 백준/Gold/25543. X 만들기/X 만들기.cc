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

    vpi v(N);
    for(auto &i : v) cin>>i.first>>i.second;
    sort(v.begin(),v.end());

    vi q1(N,1),q2(N,1),q3(N,1),q4(N,1);

    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            if(v[i].first>v[j].first && v[i].second<v[j].second)
                q2[i] = max(q2[i],q2[j]+1);
            if(v[i].first>v[j].first && v[i].second>v[j].second)
                q3[i] = max(q3[i],q3[j]+1);
        }
    }
    
    for(int i=N-2;i>=0;i--){
        for(int j=N-1;j>i;j--){
            if(v[i].first<v[j].first && v[i].second<v[j].second)
                q1[i] = max(q1[i],q1[j]+1);
            if(v[i].first<v[j].first && v[i].second>v[j].second)
                q4[i] = max(q4[i],q4[j]+1);
        }
    }

    int ans = 1e9;
    for(int i=0;i<N;i++){
        if(q1[i]>1 && q2[i]>1 && q3[i]>1 && q4[i]>1)
            ans = min(ans, N-(q1[i]+q2[i]+q3[i]+q4[i]-3));
    }
    cout<<(ans == 1e9 ? -1 : ans);
}