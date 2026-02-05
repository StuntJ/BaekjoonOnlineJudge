#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

bool dp[101005];
void solve(int t){
    int N;
    cin>>N;

    vector<pii> v(N);
    for(auto &i : v) cin>>i.first>>i.second;

    sort(v.begin(),v.end(),[&](pii &a, pii &b){
        return a.first+a.second < b.first+b.second;
    });

    memset(dp,false,sizeof(dp));

    dp[0] = true;
    for(int i=0;i<N;i++){
        for(int j=101004;j>=0;j--){
            //1. 음식을 먹지 않는 경우
            //pass
            //2. 음식을 먹는 경우
            if(j<=v[i].first&&dp[j])
                dp[j+v[i].second] = true; 
        }
    }

    cout<<"Case #"<<t<<": ";
    for(int j=101004;j>=0;j--){
        if(dp[j]){
            cout<<j<<'\n';
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin>>t;
    int ort = t;
    while(t--){
        solve(ort-t);
    }
}