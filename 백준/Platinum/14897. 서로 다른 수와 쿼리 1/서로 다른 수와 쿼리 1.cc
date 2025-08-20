#include <bits/stdc++.h>

using namespace std;

int sqrtN;
struct Query{
    int s;
    int e;
    int idx;

    bool operator < (const Query &rhs) const{
        if(s/sqrtN!=rhs.s/sqrtN) return s/sqrtN<rhs.s/sqrtN;
        return e<rhs.e;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    sqrtN = (int)sqrt(N);
    vector<int> A(N),cp;
    for(auto &i : A) cin>>i;
    cp = A;
    int idx = 0;
    sort(cp.begin(),cp.end());
    map<int,int> mp;
    for(int i=0;i<N;i++){
        if(i!=0&&cp[i-1]<cp[i]) idx++;
        mp[cp[i]] = idx; 
    }
    for(auto &i : A) i = mp[i];

    const int LIM = 1000001;
    vector<int> cnt(LIM);
    int Q;
    cin>>Q;
    vector<Query> query(Q);
    vector<int> ans(Q);

    for(int i=0;i<Q;i++){
        int s,e;
        cin>>s>>e;
        s--;
        e--;
        query[i] = {s,e,i};
    }
    sort(query.begin(),query.end());

    int s = query[0].s, e = query[0].e;
    int ret = 0;
    for(int i=s;i<=e;i++) if(!(cnt[A[i]]++)) ret++;
    ans[query[0].idx] = ret;

    for(int i=1;i<Q;i++){   
        while(s<query[i].s) if(!(--cnt[A[s++]])) ret--;
        while(s>query[i].s) if(!(cnt[A[--s]]++)) ret++;
        while(e<query[i].e) if(!(cnt[A[++e]]++)) ret++;
        while(e>query[i].e) if(!(--cnt[A[e--]])) ret--;
        ans[query[i].idx] = ret;
    }
    for(auto i : ans) cout<<i<<'\n';
}