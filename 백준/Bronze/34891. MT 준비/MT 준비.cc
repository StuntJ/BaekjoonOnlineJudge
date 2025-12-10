#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    if(N%M==0) cout<<N/M;
    else cout<<N/M+1;
}