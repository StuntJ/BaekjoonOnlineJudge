#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    int X;
    cin>>X;

    vector<int> A(N);
    for(auto &i : A) cin>>i;

    int M = 2e9;
    for(int i=0;i<N-1;i++){
        M = min(M,A[i]+A[i+1]);
    }
    cout<<M*X;
}