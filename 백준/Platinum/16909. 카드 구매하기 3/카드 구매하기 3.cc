#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int N;
    cin>>N;

    vector<ll> v(N);
    for(auto &i : v) cin>>i;

    vector<ll> uRight(N),uLeft(N),dRight(N),dLeft(N);
    stack<ll> stu,std;

    for(int i=0;i<N;i++){ //오큰수 오작수
        while(!stu.empty() && v[stu.top()]<=v[i]){ //오큰수
            uRight[stu.top()] = i;
            stu.pop();
        }

        while(!std.empty() && v[std.top()]>=v[i]){ //오작수
            dRight[std.top()] = i;
            std.pop();
        }

        stu.push(i);
        std.push(i);
    }

    while(!stu.empty()){
        uRight[stu.top()] = N;
        stu.pop();
    }

    while(!std.empty()){
        dRight[std.top()] = N;
        std.pop();
    }

    for(int i=N-1;i>=0;i--){ //왼큰수, 왼작수
        while(!stu.empty() && v[stu.top()]<v[i]){ //왼큰수
            uLeft[stu.top()] = i;
            stu.pop();
        }
        while(!std.empty() && v[std.top()]>v[i]){ //왼작수
            dLeft[std.top()] = i;
            std.pop();
        }

        stu.push(i);
        std.push(i);
    }

    while(!stu.empty()){
        uLeft[stu.top()] = -1;
        stu.pop();
    }

    while(!std.empty()){
        dLeft[std.top()] = -1;
        std.pop();
    }

    ll ans = 0;
    for(int i=0;i<N;i++){
        ll ri = uRight[i]-i-1;
        ll le = i-uLeft[i]-1;

        ans += (1+le)*(1+ri)*v[i];
    }

    for(int i=0;i<N;i++){
        ll ri = dRight[i]-i-1;
        ll le = i-dLeft[i]-1;

        ans -= (1+le)*(1+ri)*v[i];
    }

    cout<<ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}