#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;

void init(){
    for(char i='a';i<='y';i++){
        string str;
        str += i;
        mp[str] = i;
        //cout<<str<<' ';
    }
    mp["k"] = 'c';
    mp["o"] = 'p';
    mp["p"] = 'q';
    mp["ng"] = 'o';
}

bool comp(const string &a, const string &b){
    int aidx = 0, bidx = 0;
    while(aidx<a.size()&&bidx<b.size()){
        string tokenA;
        tokenA += a[aidx++];
        if(aidx<a.size()&& a[aidx]=='g'&&a[aidx-1]=='n') tokenA += a[aidx++];

        string tokenB;
        tokenB += b[bidx++];
        if(bidx<b.size()&&b[bidx]=='g'&&b[bidx-1]=='n') tokenB += b[bidx++];

        if(mp[tokenA]>mp[tokenB]) return false;
        else if(mp[tokenA]<mp[tokenB]) return true;
    }
    if(aidx<a.size()) return false;
    else return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();
    int N;
    cin>>N;

    vector<string> vs(N);
    for(auto &i : vs) cin>>i; 

    sort(vs.begin(),vs.end(),comp);
    for(auto i : vs) cout<<i<<'\n';
}