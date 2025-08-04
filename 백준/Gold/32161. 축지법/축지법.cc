#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<vector<pi>> vvpi;
typedef vector<vector<vector<pi>>> vvvpi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<long double> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

struct disjoint_set
{
	vector<int> parent; 
	disjoint_set(int n) : parent(n)
	{
		for (int i = 0; i < n; i++) 
			parent[i] = i;
	}

	int find(int u) //정점이 어느 집합에 속하는지 알려주는 함수이다.
	{
		if (u == parent[u]) return u; 
		return parent[u] = find(parent[u]); 
	}

	bool merge(int u, int v) //u와 v를 같은 집합에 속하게 하는 함수이다.
	{
		u = find(u); v = find(v); 
		if (u == v) return false; 
		parent[u] = v;
		return true; 
	}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M,Q;
    cin>>N>>M>>Q;

    const int INF = 1e9;
    map<int,int> mp;
    disjoint_set d_set(4010);
    vvi adj(4010);
    vvi dist(4010,vi(4010,INF));
    int idx = 0;
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;

        if(mp.find(u)==mp.end()) mp[u] = idx++;
        if(mp.find(v)==mp.end()) mp[v] = idx++;

        d_set.merge(mp[u],mp[v]);
        adj[mp[u]].emplace_back(mp[v]);
        adj[mp[v]].emplace_back(mp[u]);
    }

    for(int i=0;i<idx;i++){
        queue<int> q;
        q.push(i);
        vb visited(idx);
        visited[i] = true;
        dist[i][i] = 0;

        while(!q.empty()){
            int here = q.front();
            q.pop();

            for(auto next : adj[here]){
                if(!visited[next]){
                    visited[next] = true;
                    dist[i][next] = dist[i][here]+1;
                    q.push(next);
                }
            }
        }
    }
    bool allcon = false;
    if(idx==N){
        int t = d_set.find(0);
        bool flag = false;
        for(int i=1;i<idx;i++){
            if(d_set.find(i)!=t){
                flag = true;
                break;
            } 
        }
        if(!flag) allcon = true;
    }

    while(Q--){
        int s,e;
        cin>>s>>e;
        if(s==e){
            cout<<0<<'\n';
            continue;
        } 
        if(mp.find(s)==mp.end()){
            cout<<1<<'\n';
            continue;
        } 
        if(mp.find(e)==mp.end()){
            cout<<1<<'\n';
            continue;
        } 
        s = mp[s];
        e = mp[e];
        if(!allcon) cout<<(dist[s][e]==INF ? 1 : min(2,dist[s][e]))<<'\n';
        else cout<<dist[s][e]<<'\n';
    }
}