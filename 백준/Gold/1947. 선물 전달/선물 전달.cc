#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod = 1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    ll* arr = new ll[N+1];

    arr[2] = 1;
    for(int i=3;i<=N;i++){
        arr[i] = (i-1)*(arr[i-1]+arr[i-2]);
        arr[i]%=mod;
    }
    cout<<arr[N];
}