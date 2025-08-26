#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    vector<int> A(N),B(N),C(N);
    for(auto &i : A) cin>>i;
    for(auto &i : B) cin>>i;
    for(int i=0;i<N;i++) C[i] = ((A[i]%B[i]) ? A[i]/B[i]+1 : A[i]/B[i]);
    
    ll s = 0, e = 1e9;
    ll ans = 1e9;
    while(s<=e){
        ll mid = (s+e)/2;
        ll sum = 0;
        for(auto i : C) sum += max(0LL,i-mid);
        if(sum>mid) s = mid+1;
        else{
            ans = min(ans,mid);
            e = mid-1;
        }
    }
    cout<<ans;
}