#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int sqrtN;

struct Query{
    int s;
    int e;
    int idx;

    bool operator < (const Query &rhs) const{
        if(s/sqrtN != rhs.s/sqrtN) return s/sqrtN < rhs.s/sqrtN;
        return e<rhs.e;
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
    vector<Query> qry;
    vector<int> ans(Q);
    for(int i=0;i<Q;i++){
        int s,e;
        cin>>s>>e;
        s--; e--;
        qry.push_back({s,e,i});
    }
    sort(qry.begin(),qry.end());

    const int LIM = 1000001;
    vector<int> cnt(LIM);
    int res = 0;
    int s = qry[0].s, e = qry[0].e;
    for(int i=s;i<=e;i++){
        if(!cnt[A[i]]){
            res++;
        }
        cnt[A[i]]++;
    }
    ans[qry[0].idx] = res;

    for(int i=1;i<Q;i++){
        while(s<qry[i].s) if(!(--cnt[A[s++]])) res--;
        while(s>qry[i].s) if(!(cnt[A[--s]]++)) res++;
        while(e<qry[i].e) if(!(cnt[A[++e]]++)) res++;
        while(e>qry[i].e) if(!(--cnt[A[e--]])) res--;
        ans[qry[i].idx] = res;
    }

    for(auto i : ans) cout<<i<<'\n';
}