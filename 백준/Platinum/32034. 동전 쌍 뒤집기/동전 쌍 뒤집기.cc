#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;

        stack<char> st;
        int tcnt = 0;
        ll ans = 0;
        bool flag = true;
        for(int i=0;i<N;i++){
            char x;
            cin>>x;
          
            if(st.empty()){
                if(x=='H') continue;
                else{
                    st.push(x);
                }
            }
            else{
                if(x=='H'){
                    if(st.top()=='H'){
                        st.pop();
                        ans++;
                        if(st.empty()){
                            continue;
                        }
                        if(st.top()=='T'){
                            ans+=st.size();
                        }
                        else{
                            flag = false;
                            break;
                        }
                    }
                    else st.push(x);
                }
                else{
                    if(st.top()=='T'){
                        st.pop();
                        ans++;
                        if(st.empty()){
                            continue;
                        }
                        else if(st.top()=='H'){
                            ans+=st.size();
                        }
                        else{
                            flag = false;
                            break;
                        }
                    }
                    else{
                        st.push(x);

                    }
                }
            }
            
        }
        if(!st.empty()||!flag) cout<<-1<<'\n';
        else cout<<ans<<'\n';
    }
}