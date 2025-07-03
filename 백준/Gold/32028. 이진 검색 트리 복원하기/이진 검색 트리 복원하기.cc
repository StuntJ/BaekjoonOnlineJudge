#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<pair<int,int>> v(N); //first==depth, second==num
    unordered_map<int,pair<int,int>> mp;
    for(int i=0;i<N;i++){
        cin>>v[i].second>>v[i].first;
        mp[v[i].second] = {i+1,v[i].first};
    }
    sort(v.begin(),v.end());
    set<int> st;
    if(v[0].first!=1){
        cout<<-1;
        return 0;
    }

    st.insert(v[0].second);
    vector<pair<int,int>> ans(N+1,{-1,-1});
    for(int i=1;i<N;i++){
        set<int>::iterator it = st.lower_bound(v[i].second);
        if(it==st.end() || ans[mp[*it].first].first!=-1){
            if(it==st.begin()){
                cout<<-1;
                return 0;
            }
            it--;
            if(ans[mp[*it].first].second!=-1){
                cout<<-1;
                return 0;
            }
            else{
                if(v[i].first==mp[*it].second+1)
                    ans[mp[*it].first].second = mp[v[i].second].first;
                else{
                    cout<<-1;
                    return 0;
                }
            }
        }
        else{
            if(v[i].first==mp[*it].second+1)
                ans[mp[*it].first].first = mp[v[i].second].first;
            else{
                cout<<-1;
                return 0;
            }
        }
        st.insert(v[i].second);
    }

    for(int i=1;i<=N;i++) cout<<ans[i].first<< ' ' << ans[i].second<<'\n';
}