#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fpow(ll n, ll p){
    if(p==0) return 1;
    ll temp = fpow(n,p/2);
    ll ret = temp*temp;
    if(p&1) return ret*n;
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;

    while(T--){
        ll N;
        cin>>N;

        string str = to_string(N);
        ll sz = str.size();
        bool flag = false;
        for(int i=0;i<sz;i++){
            if(str[i]>'1'){
                flag = true;
                break;
            }
        }

        ll mx = (1<<(sz-1));
        set<ll> st;
            
        for(int num=0; num<mx; num++){
            int prev = 0;
            int cnt = 1;
            ll ret = 0;
            for(int i=0;i<sz-1;i++){
                ll t = (1LL<<i);
                if(t&num){
                    ret += stoll(str.substr(prev,cnt));
                    prev = i+1;
                    cnt = 1;
                }
                else{
                    cnt++;
                }          
            }
            ret += stoll(str.substr(prev));
            st.insert(ret);
        }  

        if(!flag){
            int oneNum = 0;
            for(auto i : str) if(i=='1') oneNum++;
            if(st.find(oneNum)!=st.end()){
                cout<<"Hello, BOJ 2023!\n";
            }
            else cout<<0<<'\n';;
        }
        else{
            ll res = 0;
            ll m = 1;

            for(auto i : str){
                res += fpow((i-'0'),m);
            }
            ll cnt = 0;
            while(res<=N){  
                if(st.find(res)!=st.end()){
                    cnt++;     
                }
                res = 0;
                m++;
                for(auto i : str){
                    res += fpow((i-'0'),m);
                }
            }
            cout<<cnt<<'\n';
        }
    }
}