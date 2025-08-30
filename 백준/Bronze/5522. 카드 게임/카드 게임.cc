#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x;
    int ans = 0;
    for(int i=0;i<5;i++){
        cin>>x;
        ans+=x;
    }
    cout<<ans;
}