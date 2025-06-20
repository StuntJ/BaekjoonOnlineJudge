#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    stack<int> st;
    int cnt = 0;
    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        while(!st.empty()&&st.top()>y){
            cnt++;
            st.pop();
        }

        if(!st.empty()&&st.top()==y) continue;
        st.push(y);
    }
    while(!st.empty()&&st.top()>0){ 
        cnt++;
        st.pop();
    }
    cout<<cnt;
}