#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

pair<vector<int>,vector<int>> SuffixArray(const string &s){
    int n = s.size(), m = max(n,256);
    vector<int> sa(n), lcp(n), pos(n), tmp(n), cnt(m);
    auto counting_sort = [&](){
        fill(cnt.begin(),cnt.end(),0);
        for(int i=0;i<n;i++) cnt[pos[i]]++;
        partial_sum(cnt.begin(),cnt.end(),cnt.begin());
        for(int i=n-1;i>=0;i--) sa[--cnt[pos[tmp[i]]]] = tmp[i];
    };
    
    for(int i=0;i<n;i++) sa[i] = i, pos[i] = s[i], tmp[i] = i;
    counting_sort();

    for(int k=1; ;k<<=1){
        int p = 0;
        for(int i=n-k;i<n;i++) tmp[p++] = i;
        for(int i=0;i<n;i++) if(sa[i]>=k) tmp[p++] = sa[i]-k;
        counting_sort();
        tmp[sa[0]] = 0;
        for(int i=1; i<n; i++){
            tmp[sa[i]] = tmp[sa[i-1]];
            if(sa[i-1]+k<n && sa[i]+k<n&& pos[sa[i-1]]==pos[sa[i]]&&pos[sa[i-1]+k]==pos[sa[i]+k]) continue;
            tmp[sa[i]] += 1;
        }
        swap(pos,tmp); if(pos[sa.back()]+1==n) break;
    }

    for(int i=0, j=0; i<n; i++, j=max(j-1,0)){
        if(pos[i]==0) continue;
        while(sa[pos[i]-1]+j<n && sa[pos[i]]+j<n &&s[sa[pos[i]-1]+j]==s[sa[pos[i]]+j])
            j++;
        
        lcp[pos[i]] = j;
    }

    return {sa,lcp};
}

void solve(){
    string T,S;
    cin>>T>>S;

    string com = T+"$"+S;

    auto [sa,lcp] = SuffixArray(com);

    int ans = 0;
    int pivot = 0;

    for(int i=0;i<lcp.size()-1;i++){
        //cout<<com.substr(sa[i])<<'\n';
        // cout<<com.substr(sa[i])<<'\n';
        // cout<<com.substr(sa[i+1])<<'\n';
        // cout<<lcp[i+1]<<'\n';
        if(sa[i]<T.size() && sa[i+1]>T.size() || sa[i]>T.size() && sa[i+1]<T.size()){
            //cout<<com.substr(sa[i])<<'\n';
            //cout<<com.substr(sa[i+1])<<'\n';
            if(ans<lcp[i+1]){
                ans = lcp[i+1];
                pivot = i;
            }
            ans = max(lcp[i+1],ans);
        }
    }

    cout<<ans<<'\n';
    cout<<com.substr(sa[pivot],lcp[pivot+1])<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}