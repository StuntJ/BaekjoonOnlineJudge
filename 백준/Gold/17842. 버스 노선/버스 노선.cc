#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<int> degree(N);

    for(int i=0;i<N-1;i++){
        int x,y;
        cin>>x>>y;
        degree[x]++;
        degree[y]++;
    }

    int cnt = 0;
    for(int i=0;i<N;i++){
        if(degree[i]==1) cnt++;
    }
    cout<<(cnt+1)/2;
}