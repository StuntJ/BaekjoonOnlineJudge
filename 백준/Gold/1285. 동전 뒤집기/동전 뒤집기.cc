#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<int> v(N);
    for(int i=0;i<N;i++){
        vector<char> temp(N);
        for(auto &j : temp) cin>>j;
        reverse(temp.begin(),temp.end());
        int x = 0;
        for(int j=0;j<N;j++){
            if(temp[j]=='T') x+=(1<<j);
        }
        v[i] = x;
    }

    /* for(auto i: v) cout<<i<< ' '; */
    int ans = 50000;
    for(int i=0;i<(1<<N);i++){
        int path = i;
        int cnt = 0;
        for(int j=0;j<N;j++){
            int var = (1<<j);
            int t = 0;
            for(int k=0;k<N;k++){
                if(path&(1<<k)){
                    if((v[k]&var)==0){
                        t++;
                    }
                }else{
                    if(v[k]&var){
                        t++;
                    }
                }
            }
            if(t>N/2) t = N-t;
            //cout<<"t : "<<t<<'\n';
            cnt += t;
        }
        //cout<<cnt<<'\n';
        ans = min(cnt,ans);
    }
    cout<<ans;
}