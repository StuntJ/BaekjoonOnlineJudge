#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<vector<pi>> vvpi;
typedef vector<vector<vector<pi>>> vvvpi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<long double> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin>>str;

    int sz = str.size();
    vvb dp(sz,vb(sz));

    for(int i=0;i<sz;i++){
        if(i>0) dp[i-1][i] = ((str[i-1] == '(' && str[i] == ')') || (str[i-1] == ')' && str[i] == '('));
    }

    for(int i=0;i<sz-1;i++){
        if(dp[i][i+1]){
            int x = i-1;
            int y = i+2;
            while(x>=0 && y<sz && ((str[x]=='(' && str[y]==')') || (str[x]==')' && str[y]=='('))){
                dp[x][y]=true;
                x--;
                y++;
            }
        }
    }

    int cnt = 0;
    for(int i=0;i<sz;i++){
        stack<char> st;
        for(int j=i;j<sz;j++){
            if(st.empty()){
                st.push(str[j]);
            } 
            else if(st.top()=='('){
                if(str[j]==')'){
                    st.pop();
                    if(st.empty()){
                        if(dp[i][j]){
                            //cout<<i<<' '<<j<<'\n';
                            cnt++;
                        } 
                    }
                }
                else st.push(str[j]);
            }
        }
    }
    /* for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++) cout<<dp[i][j]<<' ';
        cout<<'\n';
    } */
    cout<<cnt;
}