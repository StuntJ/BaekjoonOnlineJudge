#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 300;
    for(int i=0;i<4;i++){
        int x;
        cin>>x;
        sum+=x;
    }
    cout<<(sum>1800 ? "No" : "Yes");
}