#include <bits/stdc++.h>

using namespace std;

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

struct Query{
    int s;
    int e;
    int idx;

    bool operator < (const Query &rhs) const{
        if(e!=rhs.e) return e<rhs.e;
        return s<rhs.s;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    vector<int> v(N+1);
    for(int i=2;i<=N;i++) cin>>v[i];

    int Q;
    cin>>Q;
    vector<int> ans(Q);
    vector<Query> query(Q);
    for(int i=0;i<Q;i++){
        int s,e;
        cin>>s>>e;
        query[i] = {s,e,i};
    }
    sort(query.begin(),query.end());

    int idx = 1;
    FenwickTree seg(N+1);
    for(int i=0;i<Q;i++){
        int s = query[i].s;
        int e = query[i].e;
        while(idx<=e){
            seg.add(v[idx],1);
            idx++;
        }
        int ret = e-s+1;
        ret -= seg.sum(e)-seg.sum(s-1);
        ans[query[i].idx] = ret;
    }
    for(auto i : ans) cout<<i<<'\n';
     
}