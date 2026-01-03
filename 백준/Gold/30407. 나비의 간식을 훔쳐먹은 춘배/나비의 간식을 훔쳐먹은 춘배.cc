#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    int H,D,K;
    cin>>H>>D>>K;

    vector<int> R(N);
    for(auto &i : R) cin>>i;

    const int INF = 1e9;

    auto f = [&](auto &f, int dist, bool used, bool discard, int day)->int{
        if(day==N) return 0;
        if(discard == true) return f(f,dist+K,true,false,day+1);
        int ret = INF;
        int crawlDamage = f(f,dist,used,false,day+1) + max(0,R[day]-dist)/2;
        int runawayDamage = f(f,dist+K,used,false,day+1) + max(0,R[day]-dist-K);
        ret = min(crawlDamage,runawayDamage);
        if(!used){
            int discardDamage = f(f,dist,true,true,day+1) + max(0,R[day]-dist);
            ret = min(ret,discardDamage);
        }    
        return ret;
    };

    int minDamage = f(f,D,false,false,0);
    if(H>minDamage) cout<<H-minDamage;
    else cout<<-1;
}