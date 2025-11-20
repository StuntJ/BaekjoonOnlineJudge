#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,Q;    
    cin>>N>>Q;
    vector<ll> v(N+1);
    for(int i=1;i<=N;i++) cin>>v[i];
    for(int i=1;i<=N;i++) v[i]+=v[i-1];

    int offset = 0;
    while(Q--){
        int q;
        cin>>q;
        if(q==1){
            int k;
            cin>>k;
            offset -= k;
            offset = (offset+N)%N;
        }
        else if(q==2){
            int k;
            cin>>k;
            offset += k;
            offset = (offset+N)%N;
        }
        else{ //q==3
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            int na = (a + offset)%N;
            int nb = (b + offset)%N;
            if(na<=nb){
                cout<<v[nb+1]-v[na]<<'\n';
            }
            else{
                cout<<v[nb+1]-v[0] + v[N]- v[na]<<'\n';
            }
        }
    }
}