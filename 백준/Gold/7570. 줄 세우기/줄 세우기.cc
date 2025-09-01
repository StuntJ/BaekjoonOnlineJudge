#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<int> v(N);
    for(auto &i : v) cin>>i;

    vector<int> dp(N+1);
    for(auto i : v){
        if(i>0) dp[i] = dp[i-1]+1;
    }
    /* for(auto &i : dp) cout<<i<<' ';
    cout<<'\n'; */
    cout<<N-(*max_element(dp.begin(),dp.end()));
}