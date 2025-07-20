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

    int N,K;
    cin>>N>>K;

    vector<int> v1(N),v2(N);
    vector<int> p1(N),p2(N);
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        v1[i] = x;
        p1[x] = i;
    }

    
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        v2[i] = x;
        p2[p1[x]] = i;
    }
    //for(auto &i : p2) cout<<i<<' ';

    set<int> st(p2.begin(),p2.end());

    ll sum = 0;
    vector<pair<int,int>> vp;
    bool flag = false;
    for(int i=0;i<N;i++){
        auto it = st.upper_bound(p2[i]);
        int x = v1[i];
        while(it!=st.end() && vp.size()<K){
            vp.push_back({x,v2[*it]});
            it = st.upper_bound(*it);
        }
        if(vp.size()==K){
            flag = true;
            break;
        }
        st.erase(p2[i]);
    }
    if(flag){
        cout<<"Yes\n";
        for(auto &i : vp){
            cout<<i.first<<' '<<i.second<<'\n';
        }
    } 
    else{
        cout<<"No\n";
    }
}