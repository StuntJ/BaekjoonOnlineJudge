#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M,K;
    cin>>N>>M>>K;

    int t1 = min(M,K);
    int t2 = min(M,N-K);
    int t3 = min(N-M,N-K);
    int t4 = min(N-M,K);

    cout<<t1+t3;
}