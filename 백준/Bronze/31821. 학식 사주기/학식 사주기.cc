#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<int> v(N+1);
    for(int i=1;i<=N;i++) cin>>v[i];

    int M;
    cin>>M;
    int sum = 0;
    for(int i=0;i<M;i++){
        int x;
        cin>>x;
        sum += v[x];
    }
    cout<<sum;
}