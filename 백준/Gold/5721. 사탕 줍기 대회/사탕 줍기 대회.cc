#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        int N,M;
        cin>>N>>M;

        if(N==0) return 0;

        vector<int> val;
        for(int i=0;i<N;i++){
            vector<int> dp(M);
            for(auto &j : dp) cin>>j;
            for(int j=2;j<M;j++){
                int maxi = 0;
                maxi = dp[j-2];
                if(j>2) maxi = max(maxi,dp[j-3]);
                dp[j]+=maxi;
            }
            val.push_back(*max_element(dp.begin(),dp.end()));
        }

        for(int i=2;i<N;i++){
            int maxi = 0;
            maxi = val[i-2];
            if(i>2) maxi = max(maxi,val[i-3]);
            val[i]+=maxi;
        }
        cout<<*max_element(val.begin(),val.end())<<'\n';
    }
}