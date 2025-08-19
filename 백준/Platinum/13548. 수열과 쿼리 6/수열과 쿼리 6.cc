#include <bits/stdc++.h>

using namespace std;

int sqrtN;
struct Query{
    int s;
    int e;
    int idx;
    bool operator < (const Query &rhs) const{
        if(s/sqrtN==rhs.s/sqrtN) return e<rhs.e;
        return s/sqrtN<rhs.s/sqrtN;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    sqrtN = (int)sqrt(N);

    vector<int> A(N);
    for(auto &i : A) cin>>i;

    int Q;
    cin>>Q;
    vector<Query> query(Q);

    for(int i=0;i<Q;i++){
        int s,e;
        cin>>s>>e;
        s--; e--;
        query[i] = {s,e,i};
    }
    sort(query.begin(),query.end());
    const int LIM = 100001;
    vector<int> cnt(LIM);
    unordered_map<int,int> mp;
    vector<int> ans(Q);
    mp[0] = LIM;
    int s = query[0].s, e = query[0].e;
    int ret = 0;
    for(int i=s;i<=e;i++){
        --mp[cnt[A[i]]]; 
        cnt[A[i]]++;
        ++mp[cnt[A[i]]];
        ret = max(ret,cnt[A[i]]);
    }
    ans[query[0].idx] = ret;

    for(int i=1;i<Q;i++){
        while(s<query[i].s){
            mp[cnt[A[s]]]--;
            if(mp[cnt[A[s]]]==0 && ret == cnt[A[s]]) ret--;
            cnt[A[s]]--;
            mp[cnt[A[s]]]++;
            s++;
        }
        while(s>query[i].s){
            --s;
            mp[cnt[A[s]]]--;
            cnt[A[s]]++;
            mp[cnt[A[s]]]++;
            ret = max(ret,cnt[A[s]]);
        }
        while(e>query[i].e){
            mp[cnt[A[e]]]--;
            if(mp[cnt[A[e]]]==0 && ret == cnt[A[e]]) ret--;
            cnt[A[e]]--;
            mp[cnt[A[e]]]++;
            e--;
        }
        while(e<query[i].e){
            ++e;
            mp[cnt[A[e]]]--;
            cnt[A[e]]++;
            mp[cnt[A[e]]]++;
            ret = max(ret,cnt[A[e]]);
        }
        ans[query[i].idx] = ret;
    }
    for(auto &i : ans) cout<<i<<'\n';
}