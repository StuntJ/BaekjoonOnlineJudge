#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    for(int i=0;i<N;i++){
        int s,e;
        cin>>s>>e;
    }


    ll sum = 0;
    for(int i=0;i<M;i++){
        ll t,p;
        cin>>t>>p;

        sum += p;
    }
    cout<<fixed;
    cout.precision(4);

    cout<<(double)sum/N;
}