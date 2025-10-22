#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N,M;
    cin>>N>>M;

    cout<<(N*M%2 ? (N*M-1)/2 : N*M/2);
}