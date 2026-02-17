#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 180;

void solve(){
    int N;
    cin>>N;
    
    vector<int> an(N);
    for(auto &i : an) cin>>i;

    if(N&1){
        cout<<"NO\n";
        return;
    }

    vector<vector<vector<bool>>> dp(N+1,vector<vector<bool>>(N/2+1,vector<bool>(mod)));
    dp[0][0][0] = true;

    for(int i=0;i<N;i++){
        for(int j=0;j<=N/2;j++){
            for(int k=0;k<mod;k++){
                if(dp[i][j][k]){
                    if(j!=N/2){ //더하는거 가능?
                        dp[i+1][j+1][(k+an[i])%mod] = true;    
                    }
                    dp[i+1][j][(k-an[i]+mod)%mod] = true; 
                }
            }
        }
    }

    if(dp[N][N/2][0]){
        cout<<"YES\n";
        vector<int> even;
        vector<int> odd;

        int here = 0;
        int layer = N/2;
        for(int i=N-1;i>=0;i--){ //an[i]에 대해서
            if(layer>0 && dp[i][layer-1][(here-an[i]+mod)%mod]){
                layer--;
                here = (here-an[i]+mod)%mod;
                even.push_back(i);
            }
            else{
                here = (here+an[i])%mod;
                odd.push_back(i);
            }
        }

        int cnt = 0;
        while(!even.empty()||!odd.empty()){
            if(cnt&1){
                cout<<odd.back()+1<<' ';
                odd.pop_back();
            }
            else{
                cout<<even.back()+1<<' ';
                even.pop_back();
            }
            cnt++;
        }
    }
    else{
        cout<<"NO\n";
    }
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}