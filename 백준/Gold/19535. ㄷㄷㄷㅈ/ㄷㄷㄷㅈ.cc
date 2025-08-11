#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    vector<vector<int>> adj(N+1);
    vector<ll> inDegree(N+1);

    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        inDegree[a]++;
        inDegree[b]++;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    ll d = 0;
    ll z = 0;
    for(int i=1;i<=N;i++){
        if(inDegree[i]>=2){
            for(int next : adj[i]){
                if(inDegree[next]>=2){
                    d += (inDegree[i]-1)*(inDegree[next]-1);
                }
            }
            z += inDegree[i]*(inDegree[i]-1)*(inDegree[i]-2)/6;
        }
    }
    d/=2;
    if(z*3==d) cout<<"DUDUDUNGA";
    else if(z*3>d) cout<<"G";
    else cout<<"D";
}