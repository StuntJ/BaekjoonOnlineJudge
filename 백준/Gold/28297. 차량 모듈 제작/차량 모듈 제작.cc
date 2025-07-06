#include <bits/stdc++.h>

using namespace std;

struct circle{
    long double x;
    long double y;
    long double r;
};
const long double PI = 3.14159265358979323846;

long double getBeltLength(circle &a, circle &b){
    long double dist = hypot(a.x-b.x,a.y-b.y);
    long double theta = acos((b.r-a.r)/dist);
    long double side = sqrt(dist*dist-(b.r-a.r)*(b.r-a.r));
    return 2*(b.r*(PI-theta)+a.r*theta+side);
}

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

struct edgeData{
    int st;
    int nd;
    long double dist;

    bool operator < (const edgeData &rhs) const{
        return dist<rhs.dist;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout<<fixed;
    cout.precision(6);

    int N;
    cin>>N;
    vector<circle> v(N);
    vector<bool> visited(N);
    for(auto &i : v) cin>>i.x>>i.y>>i.r;

    vector<vector<circle>> stv;
    disjoint_set circleSet(N);
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            long double d = hypot(v[i].x-v[j].x,v[i].y-v[j].y);
            if(d<=v[i].r+v[j].r){
                circleSet.merge(i,j);
            }
        }
    }
    map<int,int> mp;
    int sz = 0;
    for(int i=0;i<N;i++){
        int p = circleSet.find(i);
        if(mp.find(p)==mp.end()){
            mp[p] = sz++;
            stv.push_back(vector<circle>());
        } 
        stv[mp[p]].push_back(v[i]);
    }

    vector<edgeData> mst;
    for(int i=0;i<sz;i++){
        for(int j=i+1;j<sz;j++){
            long double minL = 1e10;
            for(int k=0;k<stv[i].size();k++){
                for(int l=0;l<stv[j].size();l++){
                    minL = min(minL,getBeltLength(stv[i][k],stv[j][l]));
                }
            }
            mst.push_back({i,j,minL});       
        }
    }

    sort(mst.begin(),mst.end());
    disjoint_set d_set(sz);
    long double ans = 0;
    for(int i=0;i<mst.size();i++){
        if(!d_set.merge(mst[i].st,mst[i].nd)) continue;
        ans += mst[i].dist;
    }
    cout<<ans;
}