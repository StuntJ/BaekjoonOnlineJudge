#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll cnt[1<<10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,K;
    cin>>N>>K;
    
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        int idx = 0;
        for(auto ch : str){
            int k = ch-'0';
            idx |= (1<<k);
        }
        cnt[idx]++;
    }

    ll ans = 0;
    for(int i=0;i<(1<<10);i++){
        for(int j=i+1;j<(1<<10);j++){
            if(__builtin_popcount(i|j)==K){
                ans += cnt[i]*cnt[j];
            } 
        }
    }
    
    for(int i=0;i<(1<<10);i++){
        if(__builtin_popcount(i)==K){
            ans += cnt[i]*(cnt[i]-1)/2;
        }
    }
    cout<<ans;
}