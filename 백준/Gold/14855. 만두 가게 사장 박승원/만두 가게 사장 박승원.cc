#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M,c0,d0;
    cin>>N>>M>>c0>>d0;
    vector<vector<int>> dp(M+2,vector<int>(N+1));
    struct d_data{
        int a;
        int b;
        int c;
        int d;
    };
    vector<d_data> vd;
    vd.push_back({0,0,c0,d0});
    for(int i=0;i<M;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        vd.push_back({a,b,c,d});
    }
    vd.insert(vd.begin(),{0,0,0,0});

    for(int n=1;n<=M+1;n++){
        for(int v=0;v<=N;v++){
            for(int k=0;v-vd[n].c*k>=0&&vd[n].a>=vd[n].b*k;k++){
                dp[n][v] = max(dp[n-1][v-vd[n].c*k]+vd[n].d*k,dp[n][v]);
            }
        }
    }

    cout<<dp[M+1][N];
}