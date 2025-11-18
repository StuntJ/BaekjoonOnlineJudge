#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    
    if(A+C>B+D) cout<<"Yongdap";
    else if(A+C<B+D) cout<<"Hanyang Univ.";
    else cout<<"Either";
}