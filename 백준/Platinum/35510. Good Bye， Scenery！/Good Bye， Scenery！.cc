#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;

struct v_data {
    int val;
    int idx;

    bool operator < (const v_data &rhs) const {
        return idx < rhs.idx;
    }
};

struct FenwickTree
{
    vector<int> tree;
    FenwickTree(int n) : tree(n + 1) {} //index 조작을 위해 1~n 을 인덱스로 설정
    int sum(int pos) //구간 합을 구하는 함수
    {
        pos++; //0~n-1 을 인덱스로 설정했을때 1~n으로 바꾸기 위해 pos++
        int ret = 0;
        while (pos > 0) //더 이상 위로 올라갈 수 없을 때
        {
            ret += tree[pos];
            pos &= (pos - 1); //마지막 비트 제거
        }
        return ret;
    }

    void add(int pos, int val) //pos에 val이 추가됨
    {
        pos++; //0~n-1 을 인덱스로 설정했을때 1~n으로 바꾸기 위해 pos++
        while (pos < tree.size()) //더 이상 위로 올라갈 수 없을 때
        {
            tree[pos] += val; //노드에 val 더하기
            pos += (pos & -pos); //마지막 비트를 계산하여 원래 노드에 그대로 더해주면 다음 노드를 구할 수 있다.
        }
    }
};

void solve() {
    int N;
    cin>>N;

    vector<v_data> v(N);
    for (int i=0;i<N;i++) {
        cin>>v[i].val;
        v[i].idx = i;
    }
    sort(all(v),[&](v_data &a, v_data &b) {
        return a.val>b.val;
    });

    priority_queue<v_data> pq;

    int idx = 0;
    vector<int> cycle(N);
    for (int i=N-1;i>=0;i--) {
        while (idx<N && v[idx].val>=i+1) {
            pq.push(v[idx]);
            idx++;
        }

        if (pq.empty()) {
            cout<<"-1\n";
            return;
        }

        cycle[pq.top().idx] = i;
        pq.pop();
    }

    FenwickTree fTree(N);

    // for (auto &i : cycle) cout<<i<<' ';
    // cout<<'\n';

    ll ans = 0;
    for (int i=0;i<N;i++) {
        ans += fTree.sum(N-1) - (cycle[i]>0 ? fTree.sum(cycle[i]-1) : 0);
        fTree.add(cycle[i],1);
    }

    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin>>t;
    while (t--) solve();
}