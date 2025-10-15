#include <bits/stdc++.h>

using namespace std;

const int mod = 100999;

const int MAX_N = 2001;

int main(){
    int T;
    cin>>T;

    vector<int> dp(MAX_N);
    dp[0] = 1;

    for(int i=1;i<MAX_N;i++){
        for(int j=MAX_N-1;j>=i;j--){
            dp[j] = (dp[j]+dp[j-i])%100999;
        }
    }
    while(T--){
        int N;
        cin>>N;
        
        cout<<dp[N]<<'\n';
        
    }
}