#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin>>str;

    stack<char> st;

    int cnt = 0;
    for(int i=0;i<str.size();i++){
        if(str[i]==')'){
            st.pop();
            continue;
        }
        if(str[i]=='*'){
            cnt = st.size();
            break;
        }
        st.push(str[i]);
    }
    cout<<cnt<<'\n';
}