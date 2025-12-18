#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int convert(char t){
    switch(t){
        case 'U':
        return 0;
        case 'O':
        return 1;
        case 'S':
        return 2;
        case 'P':
        return 3;
        case 'C':
        return 4;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin>>N;
    
    string str;
    cin>>str;
    
    vector<ll> a(N);
    for(auto &i : a) cin>>i;
    
    const ll INF = 4e18;
    vector<ll> t(5,INF);
    
    
    
    for(int i=0;i<N;i++){
        int x = convert(str[i]);
        if(x==0) t[x] = min(a[i],t[x]);
        else{
            if(t[x-1]==INF) continue;
            else{
                t[x] = min(a[i]+t[x-1],t[x]);
            }
        }
    }
    if(t[4]==INF) cout<<-1;
    else cout<<t[4];
}