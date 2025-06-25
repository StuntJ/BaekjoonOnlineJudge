#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    const int LIM = 101;
    vector<vector<int>> loc(LIM);
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        loc[x].emplace_back(i);
    } 

    int ans = 1;
    for(int i=1;i<LIM;i++){
        if(loc[i].empty()) continue;
        for(int j=-99;j<=99;j++){
            int p = i;
            int d = j;
            int here = loc[i][0];

            int cnt = 1;
            while(p+d>0 && p+d<LIM){
                int next = p+d;
                auto it = upper_bound(loc[next].begin(),loc[next].end(),here);
                if(it==loc[next].end()) break;
                p = next;
                cnt++;
                here = *it;
            }
            ans = max(cnt,ans);
        }
    }
    cout<<ans;
}