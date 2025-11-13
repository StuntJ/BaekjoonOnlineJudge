#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c,h;
    cin>>c>>h;

    vector<string> v(c+h);
    for(auto &i : v) cin>>i;
    sort(v.begin(),v.end());

    int hh;
    int mm;
    int ss;

    auto extract = [&](string str){
        hh = stoi(str.substr(0,2));
        mm = stoi(str.substr(3,2));
        ss = stoi(str.substr(6,2));
    };

    vector<bool> chk(86400);
    for(int i=0;i<c+h;i++){
        extract(v[i]);
        int timer = hh*3600 + mm*60+ss;
        for(int i=0;i<40;i++) chk[timer+i] = true;
    }

    int cnt = 0;
    for(int i=0;i<86400;i++) if(!chk[i]) cnt++; 
    
    cout<<cnt;
}