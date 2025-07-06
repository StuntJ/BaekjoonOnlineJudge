#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,K;
    cin>>N>>K;
    vector<int> v(N),ans(N);
    for(auto &i : v) cin>>i;
    for(auto &i : ans) cin>>i;

    int an = 0;
    auto solve = [&](auto &solve, int n, vector<int> v)->void{
        if(n==0){
            int cnt = 0;
            for(int i=0;i<N;i++){
                if(v[i]==ans[i]) cnt++;
            }
            an = max(an,cnt);
            return;
        }
        solve(solve,n-1,v);
        for(int i=0;i<N;i++){
            vector<int> rr = v;
            rotate(rr.begin()+i,rr.begin()+i+1,rr.end());
            rr.back() = -1;
            solve(solve,n-1,rr);
            vector<int> rl = v;
            rotate(rl.begin()+i,rl.end()-1,rl.end());
            rl[i] = -1;
            solve(solve,n-1,rl);
        }
    };

    solve(solve,K,v);
    cout<<an<<'\n';
}