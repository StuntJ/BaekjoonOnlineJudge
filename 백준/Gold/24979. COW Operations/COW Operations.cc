#include <bits/stdc++.h>

using namespace std;

void solve(){
    string str;
    cin>>str;

    str.insert(str.begin(),0);
    int sz = str.size();
    vector<int> pC(sz+1),pO(sz+1),pW(sz+1);

    for(int i=1;i<=sz;i++){
        if(str[i]=='C') pC[i]++;
        else if(str[i]=='O') pO[i]++;
        else pW[i]++; 
    }

    for(int i=1;i<=sz;i++){
        pC[i] += pC[i-1];
        pO[i] += pO[i-1];
        pW[i] += pW[i-1];
    }

    int Q;
    cin>>Q;
    while(Q--){
        int l,r;
        cin>>l>>r;
        
        int cNum = pC[r]-pC[l-1];
        cNum %= 2;
        int oNum = pO[r]-pO[l-1];
        oNum %= 2;
        int wNum = pW[r]-pW[l-1];
        wNum %= 2;

        if(cNum>=1 && oNum==0 && wNum==0) cout<<"Y";
        else if(oNum>=1 && wNum>=1 && cNum==0) cout<<"Y";
        else cout<<"N";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}