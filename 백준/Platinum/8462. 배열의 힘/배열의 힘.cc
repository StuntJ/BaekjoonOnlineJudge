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

    vector<ll> A(N);
    for(auto &i : A) cin>>i;

    vector<Query> query(Q);
    vector<ll> ans(Q);
    const int LIM = 1000001;
    vector<ll> cnt(LIM);

    for(int i=0;i<Q;i++){
        int s,e;
        cin>>s>>e;
        s--; e--;
        query[i] = {s,e,i};
    }
    sort(query.begin(),query.end());

    ll ret = 0;
    int s = query[0].s, e = query[0].e;
    for(int i=s;i<=e;i++){
        ret -= cnt[A[i]]*cnt[A[i]]*A[i];
        cnt[A[i]]++;
        ret += cnt[A[i]]*cnt[A[i]]*A[i];
    }
    ans[query[0].idx] = ret;

    for(int i=1;i<Q;i++){
        while(s<query[i].s){
            ret -= cnt[A[s]]*cnt[A[s]]*A[s];
            cnt[A[s]]--;
            ret += cnt[A[s]]*cnt[A[s]]*A[s];
            s++;
        }
        while(s>query[i].s){
            s--;
            ret -= cnt[A[s]]*cnt[A[s]]*A[s];
            cnt[A[s]]++;
            ret += cnt[A[s]]*cnt[A[s]]*A[s];
        }
        while(e<query[i].e){
            e++;
            ret -= cnt[A[e]]*cnt[A[e]]*A[e];
            cnt[A[e]]++;
            ret += cnt[A[e]]*cnt[A[e]]*A[e];
        }
        while(e>query[i].e){
            ret -= cnt[A[e]]*cnt[A[e]]*A[e];
            cnt[A[e]]--;
            ret += cnt[A[e]]*cnt[A[e]]*A[e];
            e--;
        }
        ans[query[i].idx] = ret;
    }
    for(auto &i : ans) cout<<i<<'\n';
}