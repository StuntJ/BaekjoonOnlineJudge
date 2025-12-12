#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin>>str;

    int cnt = 0;
    for(int i=0;i+4<=str.size();i++){
        if(str.substr(i,4)=="DKSH") cnt++;
    }
    cout<<cnt;
}