#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MX_N = 200010;

struct disjoint_set
{
	vector<int> parent, rank; 
	disjoint_set(int n) : parent(n), rank(n, 1) 
	{
		for (int i = 0; i < n; i++) 
			parent[i] = i; 
	}

	int find(int u)
	{
		if (u == parent[u]) return u; 
		return parent[u] = find(parent[u]);
	}

	bool merge(int u, int v)
	{
		u = find(u); v = find(v); 
		if (u == v) return false; 
		if (rank[u] > rank[v]) swap(u, v); 
		parent[u] = v;
		if (rank[u] == rank[v]) rank[v]++; 
		return true; 
	}
};

void solve(){
    int N;
    cin>>N;

    vector<deque<ll>> v(N);
    vector<int> rep(MX_N);
    disjoint_set d_set(MX_N);

    int sum = 0;
    for(int i=0;i<N;i++){
        int sz;
        cin>>sz;
        for(int j=0;j<sz;j++){
            int t;
            cin>>t;
            if(!v[i].empty()) d_set.merge(v[i].back(),t);
            v[i].push_back(t);
            rep[t] = i;
        }
        sum += sz;
    }

    int Q;
    cin>>Q;

    vector<bool> isLinked;
    vector<array<ll,3>> query2;
    vector<string> ans(Q);

    for(int i=0;i<Q;i++){
        int q;
        cin>>q;

        if(q==1){
            int a,b;
            cin>>a>>b;

            int r1 = rep[d_set.find(a)];
            int r2 = rep[d_set.find(b)];

            if(!d_set.merge(a,b)){
                ans[i] = "NO";
            }
            else{
                ans[i] = "YES";
                int &r = rep[d_set.find(a)]; //합쳐진 녀석의 대표의 rep
                if(v[r1].size()>v[r2].size()){ //b를 a의 뒷부분에
                    r = r1;
                    while(!v[r2].empty()){
                        v[r1].push_back(v[r2].front());
                        v[r2].pop_front();
                    }
                }
                else{ //a를 b의 앞부분에
                    r = r2;
                    while(!v[r1].empty()){
                        v[r2].push_front(v[r1].back());
                        v[r1].pop_back();
                    }
                }
            }
        }
        else{
            int a,b;
            cin>>a>>b;
            query2.push_back({i,a,b});
            if(d_set.find(a)!=d_set.find(b)) isLinked.push_back(false);
            else isLinked.push_back(true);
        }
    }

    vector<vector<ll>> pSum;
    vector<pair<int,int>> coord(sum+1);
    int pos = 0;
    for(int i=0;i<v.size();i++){
        if(!v[i].empty()){
            vector<ll> seg;
            seg.push_back(0);
            int idx = 1;
            while(!v[i].empty()){
                seg.push_back(seg.back() + v[i].front());
                coord[v[i].front()] = {pos, idx}; 
                v[i].pop_front();
                idx++;
            }
            pos++;
            pSum.push_back(seg);
        }
    }

    for(int i=0;i<query2.size();i++){
        if(!isLinked[i]){
            ans[query2[i][0]] = "-1";
        }
        else{
            ll a = query2[i][1];
            ll b = query2[i][2];

            if(coord[a].second>coord[b].second){
                swap(a,b);
            }

            ll t = pSum[coord[b].first][coord[b].second] - pSum[coord[a].first][coord[a].second-1];

            ans[query2[i][0]] = to_string(t);
        }
    }

    for(auto i : ans) cout<<i<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}