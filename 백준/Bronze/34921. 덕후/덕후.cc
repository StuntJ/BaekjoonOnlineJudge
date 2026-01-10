#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int A,T;
    cin>>A>>T;
    
    cout<<max(0,10+2*(25-A+T));
}