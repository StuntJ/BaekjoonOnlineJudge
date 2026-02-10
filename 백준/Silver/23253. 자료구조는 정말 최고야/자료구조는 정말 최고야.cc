#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    vector<stack<int>> v(M);
    vector<int> pos(N+1);
    for(int i=0;i<M;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int x;
            cin>>x;
            v[i].push(x);
            pos[x] = i;
        }
    }

    for(int i=1;i<=N;i++){
        if(v[pos[i]].top()!=i){
            cout<<"No";
            return 0;
        }
        else{
            v[pos[i]].pop();
        }
    }
    cout<<"Yes";
}