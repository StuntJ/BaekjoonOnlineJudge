#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

template <typename T>
struct PST {
    struct Node{int l = 0, r = 0; T val; Node(T id = T{}) : val(id) {} };
    vector<Node> seg; vector<int> root; int n; T ID;

    PST(int n, T ID) : n(n), ID(ID) {
        seg.reserve(4e6);
        seg.push_back(Node(ID));
        root.push_back(build(0,n));
    }

    int build(int l, int r) {
        int cur = (int)seg.size();
        seg.push_back(Node(ID));
        if (l!=r) {
            int m = l+r>>1;
            seg[cur].l = build(l,m);
            seg[cur].r = build(m+1,r);
        }
        return cur;
    }
    T merge(T a, T b) {
        return a+b;
    }

    int upd(int prev, int l, int r, int idx, T v) {
        int cur = (int)seg.size();
        seg.push_back(seg[prev]);
        if (l==r) { seg[cur].val = v; return cur; }
        int m = l+r>>1;
        if (idx<=m) seg[cur].l = upd(seg[prev].l,l,m,idx,v);
        else seg[cur].r = upd(seg[prev].r,m+1,r,idx,v);
        seg[cur].val = merge(seg[seg[cur].l].val, seg[seg[cur].r].val);
        return cur;
    }
    int upd(int ver, int idx, T v) {
        int nr = upd(root[ver],0,n,idx,v);
        root.push_back(nr);
        return (int)root.size()-1;
    }

    T query(int node, int l, int r, int ql, int qr) {
        if (qr<l || r<ql) return ID;
        if (ql<=l&&r<=qr) return seg[node].val;
        int m = l+r>>1;
        return merge(query(seg[node].l,l,m,ql,qr), query(seg[node].r,m+1,r,ql,qr));
    }
    
    T query(int ver, int ql, int qr) {
        return query(root[ver],0,n,ql,qr);
    }
};

void solve() {
    int N;
    cin>>N;

    PST<int> pst(N,0);
    vector<int> D(N);


    int now = 0;
    auto process = [&](string& token) {
        bool plus = (token[0]=='+' ? true : false);
        int val = stoi(token.substr(1));
        if (plus) pst.upd(now,val,1);
        else pst.upd(now,val,0);
        now++;
    };
    vector<int> v(N);
    string li;
    getline(cin,li);
    for (int i=0;i<N;i++) {
        getline(cin,li);

        string token;
        int idx = 0;
        while (idx<li.size()) {
            if (li[idx]==' ') {
                if (!token.empty()) {
                    process(token);
                    token.clear();
                }
            }
            else {
                token.push_back(li[idx]);
            }
            idx++;
        }
        if (!token.empty()) {
            process(token);
            token.clear();
        }
        v[i] = now;
    }
    for (auto &i : D) cin>>i;
    int X = 0;
    for (int i=1;i<=N;i++) {
        X = (X + pst.query(v[D[i-1]-1],X,N-1))%N;
    }

    cout<<X;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while (t--) solve();
}