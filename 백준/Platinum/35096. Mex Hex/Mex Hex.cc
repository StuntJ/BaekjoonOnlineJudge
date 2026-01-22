#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int n,d;
    cin>>n>>d;

    vector<int> v(n);
    for(auto &i : v) cin>>i;

    vector<vector<int>> pos(n);
    for(int i=0;i<n;i++){
        pos[v[i]].emplace_back(i);
    }

    int ans = *max_element(v.begin(),v.end())+1;
    for(int i=0;i<n;i++){
        if(pos[i].size()==0){
            ans = i;
            break;
        }
        bool flag = false;
        int prevlim = 0;
        int j=0;
        while(j<pos[i].size()){
            int p = pos[i][j];
            if(p<prevlim){
                flag = true;
                break;
            }
            int here = p;
            int right = p;
            while(j<pos[i].size() && pos[i][j]<here+d){
                right = pos[i][j];
                j++;
            }
            int start = max(prevlim,right-d+1);
            prevlim = start+d-1+d+1;
        }

        if(!flag){
            ans = i;
            break;
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}