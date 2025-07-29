#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<int> v(N);
    for(auto &i : v) cin>>i;
    int maxi = *max_element(v.begin(),v.end());
    ll sum = accumulate(v.begin(),v.end(),0LL);
    sum-=maxi;
    if(maxi>sum){
        cout<<sum*2+1;
    }
    else{
        cout<<sum+maxi;
    }

}