#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int N,M,k,D;
        cin>>N>>M>>k>>D;

        int B = D/(M*M*(N-1)+M*(M-1)*k);
        if(B<1) cout<<-1<<'\n';
        else cout<<(M*M*(N-1)+M*(M-1)*k)*B<<'\n';
    }
}