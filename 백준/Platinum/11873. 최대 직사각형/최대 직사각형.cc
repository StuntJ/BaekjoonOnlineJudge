#include <bits/stdc++.h>

using namespace std;

int getSize(vector<int> &v){
    int sz = v.size();
    vector<int> left(sz),right(sz);
    stack<int> st;

    for(int i=0;i<sz;i++){
        while(!st.empty() && v[st.top()]>v[i]){
            right[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }
    while(!st.empty()){
        right[st.top()] = sz;
        st.pop();
    }

    for(int i=sz-1;i>=0;i--){
        while(!st.empty()&&v[st.top()]>v[i]){
            left[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    while(!st.empty()){
        left[st.top()] = -1;
        st.pop();
    }
    int ans = 0;
    for(int i=0;i<sz;i++){
        ans = max(ans,v[i]*(right[i]-left[i]-1));
    }
    return ans;
}

void solve(){
    while(true){
        int N,M;
        cin>>N>>M;

        if(N==0 && M==0) return;
        vector<vector<int>> adj(N,vector<int>(M));
        for(auto &i : adj) for(auto &j : i) cin>>j;

        vector<int> v(M);
        int ans = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(adj[i][j]==0) v[j] = 0;
                else v[j] += adj[i][j];
            }
            ans = max(ans,getSize(v));
        }

        cout<<ans<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}