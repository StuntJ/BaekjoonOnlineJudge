#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    vector<vector<char>> adj(N,vector<char>(M));
    for(auto &i : adj)
        for(auto &j : i)
            cin>>j;
    
    int bitMmax = (1<<N)-1;
    int bitWmax = (1<<M)-1;
    int maxCnt = 100;
    for(int i=0;i<=bitMmax;i++){
        int Mcnt = __builtin_popcount(i);
        for(int j=0;j<=bitWmax;j++){
            int Wcnt = __builtin_popcount(j);
            if(Mcnt+Wcnt<min(2,min(N,M))|| Mcnt+Wcnt > max(N,M) || Mcnt+Wcnt>=maxCnt) continue;
            int chkM = 0;
            int chkW = 0;
            for(int m=0;m<N;m++){
                for(int w=0;w<M;w++){
                    if(adj[m][w]=='1'&&((i&(1<<m))||(j&(1<<w)))){
                        chkM |= (1<<m);
                        chkW |= (1<<w);
                    }
                }
            }
            if(chkM==bitMmax && chkW==bitWmax)
                maxCnt = Mcnt+Wcnt;
        }
    }
    cout<<(maxCnt==100 ? -1 : maxCnt);
}