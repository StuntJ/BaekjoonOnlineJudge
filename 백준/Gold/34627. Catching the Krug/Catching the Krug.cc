#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;
    const ll INF = 1e15;
    while(T--){
        ll n,rk,ck,rd,cd;
        cin>>n>>rk>>ck>>rd>>cd;

        ll dirx = rk-rd;
        ll diry = ck-cd;
        ll abdiry = abs(diry);
        ll abdirx = abs(dirx);
        ll ordist = abdiry+abdirx;
        ll tx = 0, ty = 0;
        if(dirx<0){ //diry is diff
            tx = rk+abdirx;
            //tx = (abdiry>=rk ? abdiry : rk + abdirx);
        }
        else if(dirx>0){
            tx = n-rk +abdirx;
            //tx = (abdiry>=n-rk ? abdiry : n-rk + abdirx);
        }
        if(diry<0){ //dirx is diff
            ty = ck+abdiry;
            //ty = (abdirx>=ck ? abdirx : ck + abdiry);
        }
        else if(diry>0){
            ty = n-ck + abdiry;
            //ty = (abdirx>=n-ck ? abdirx : n-ck + abdiry); 
        }
        //cout<<tx<<' '<<ty<<'\n';
        cout<<max(tx,ty)<<'\n';
    }
}