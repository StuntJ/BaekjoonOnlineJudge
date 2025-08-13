#include <bits/stdc++.h>

using namespace std;

int fpow(int n, int p){
    if(p==0) return 1;
    int temp = pow(n,p/2);
    int ret = temp*temp;
    if(p&1) return ret*n;
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    vector<int> v(N);
    vector<pair<int,int>> vp;
    for(auto &i : v) cin>>i;
    int prev = v[0];
    int con = 1;
    for(int i=1;i<=N;i++){
        if(prev==1){
            if(i!=N && prev==v[i]) con++;
            else{
                if(con&1) vp.push_back({1,con});
                else{
                    if(!vp.empty() && vp.back().first==2) vp.back().second += con/2;
                    else vp.push_back({2,con/2});
                }
                prev = 2;
                con = 1;
            }
        }
        else{
            if(i!=N && prev==v[i]) con++;
            else{
                if(!vp.empty() && vp.back().first==2) vp.back().second += con;
                else vp.push_back({2,con});
                prev = 1;
                con = 1;
            }
        }
    }


    int ans = 0;
    for(int i=0;i<vp.size();i++){
        if(vp[i].first==1){
            ans = max(ans,fpow(2,(int)log2(vp[i].second)));
            continue;
        }
        int p = 0,q = vp[i].second,r = 0;
        if(i > 0) p = vp[i-1].second;
        if(i < vp.size() - 1) r = vp[i+1].second;
        int k = p/2 + q + r/2;
        ans = max(ans,fpow(2,(int)log2(k)+1));
    }
    cout<<ans;
}