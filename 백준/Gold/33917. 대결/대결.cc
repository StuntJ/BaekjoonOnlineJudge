#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<int> A(N);
    vector<ll> B(N),orB;

    for(auto &i : A) cin>>i;
    for(auto &i : B) cin>>i;

    for(int i=0;i<N;i++) if(A[i]==0) B[i] = -B[i];
    orB = B;
    for(int i=1;i<N;i++) B[i] += B[i-1];

    vector<int> up(N);
    int cnt = 0;
    for(int i=0;i<N-1;i++){
        if(B[N-1]>B[i]){
            up[i]++;
            cnt++;
        } 
    }
    ll sum = 0;
    ll idx = 1;
    for(int i=0;i<N;i++){
        sum += orB[i]*idx;
        if(up[i]) idx++;
    }
    cout<<cnt+1<<' '<<sum;
}