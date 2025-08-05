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

    int N;
    cin>>N;
    string str;
    cin>>str;

    stack<int> st;

    ll cnt = 0;
    for(int i=0;i<N;i++){
        switch (str[i]){
            case 's':
                st.push(1);
                break;
            case 'k':
                if(!st.empty()&&st.top()==1){
                    st.top()++;
                }
                else{
                    while(!st.empty()) st.pop();
                }
                break;
            case 'e':
                if(!st.empty()&&(st.top()==2||st.top()==3)){
                    st.top()++;
                }
                else{
                    while(!st.empty()) st.pop();
                }
                break;
            case 'p':
                if(!st.empty()&&st.top()==4){
                    st.top()++;   
                }
                else while(!st.empty()) st.pop();
                break;
            default:
                while(!st.empty()) st.pop();
                break;
        }

        while(!st.empty()&&st.top()==5){
            cnt++;
            st.pop();

            if(!st.empty()) st.top()++;
        }
    }

    cout<<cnt;
}