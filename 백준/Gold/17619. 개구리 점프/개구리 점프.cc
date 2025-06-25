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

ll Pow(ll n, ll p)
{
    if(p==1) return n;
    ll temp = Pow(n,p/2);
    ll ret = temp*temp;
    if(p&1) return ret*n;
    return ret;
}

struct disjoint_set
{
	vector<int> parent, nd;
	disjoint_set(int n, vector<int> &v) : parent(n)
	{
		for (int i = 0; i < n; i++) 
			parent[i] = i;
        
        nd = v;
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

    int N,Q;
    cin>>N>>Q;

    vector<tuple<int,int,int>> v;
    for(int i=0;i<N;i++){
        int x1,x2, y;
        cin>>x1>>x2>>y;
        v.push_back({x1,x2,i});
    }

    sort(v.begin(),v.end());
    vector<int> nd(N);
    for(auto &i : v){
        nd[get<2>(i)] = get<1>(i);
    }

    disjoint_set d_set(N,nd);

    for(int i=1;i<N;i++){
        auto [s1,e1,idx1] = v[i-1];
        auto [s2,e2,idx2] = v[i];
        int point = d_set.nd[d_set.find(idx1)];
        if(point>=s2){ 
            d_set.merge(idx1,idx2);
            d_set.nd[d_set.find(idx1)] = max(point,e2);
        }
    }

    while(Q--){
        int a,b;
        cin>>a>>b;
        a--,b--;
        if(d_set.find(a)==d_set.find(b)) cout<<1<<'\n';
        else cout<<0<<'\n';
    }
}