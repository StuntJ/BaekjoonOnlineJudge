#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long double A,B,C;

    cin>>A>>B>>C;

    cout<<(ll)max(A*B/C,A/B*C);
}