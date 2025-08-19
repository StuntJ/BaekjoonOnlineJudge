#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

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

    int N,Q;
    cin>>N>>Q;
    sqrtN = (int)sqrt(N);
    vector<int> A(N),cp;
    for(auto &i : A) cin>>i;
    unordered_map<int,int> mp;
    cp = A;
    sort(cp.begin(),cp.end());
    int idx = 0;
    for(int i=0;i<N;i++){
        if(i!=0 && cp[i-1]<cp[i]) idx++;
        mp[cp[i]] = idx;
    }
    for(int i=0;i<N;i++){
        A[i] = mp[A[i]];
    }
    
    vector<Query> query(Q);
    vector<int> ans(Q);
    vector<int> cnt(idx+1);
    for(int i=0;i<Q;i++){
        int s,e;
        cin>>s>>e;
        s--; e--;
        query[i] = {s,e,i};
    }
    sort(query.begin(),query.end());

    int s = query[0].s, e = query[0].e;
    int ret = 0;
    for(int i=s;i<=e;i++){
        if(cnt[A[i]]==2) ret--;
        cnt[A[i]]++;
        if(cnt[A[i]]==2) ret++;
    }
    ans[query[0].idx] = ret;

    for(int i=1;i<Q;i++){
        while(s<query[i].s){
            if(cnt[A[s]]==2) ret--;
            cnt[A[s]]--;
            if(cnt[A[s]]==2) ret++;
            s++;
        }   
        while(s>query[i].s){
            s--;
            if(cnt[A[s]]==2) ret--;
            cnt[A[s]]++;
            if(cnt[A[s]]==2) ret++;
        }
        while(e<query[i].e){
            e++;
            if(cnt[A[e]]==2) ret--;
            cnt[A[e]]++;
            if(cnt[A[e]]==2) ret++;
        }
        while(e>query[i].e){
            if(cnt[A[e]]==2) ret--;
            cnt[A[e]]--;
            if(cnt[A[e]]==2) ret++;
            e--;
        }
        ans[query[i].idx] = ret;
    }

    for(auto &i : ans) cout<<i<<'\n';
}