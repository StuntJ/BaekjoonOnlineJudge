#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,A,B;
    cin>>N>>A>>B;
    vector<int> v(N);
    for(auto &i : v) cin>>i;
    sort(v.begin(),v.end());
    int tot = *max_element(v.begin(),v.end());
    
    int ans = 0;
    for(int x = 0; x<A; x++){
        int sleep = x*B;
        int mx = 0;
        for(int st=0;st<=tot;st++){
            int nd = st+sleep;
            int setting = 0;
            if(nd>tot) continue;
            for(int i=0;i<N;i++){
                int sum = 0;
                if(v[i]<st){
                    sum+=v[i]/A;
                }
                else if(st<=v[i] && v[i]<nd){
                    sum+=(st)/A;
                }
                else{
                    sum += (st)/A;
                    sum += (v[i]-nd)/(A-x);
                }
                if(sum-setting>0){
                    setting++;
                }
            }
            ans = max(setting,ans);
        }
    }
    cout<<ans<<'\n';
}