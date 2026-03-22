#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define MAX_N 10010
#define INF 1e9

using namespace std;
typedef long long ll;

bool used[MAX_N]; //A에 있는 정점이 매칭되었는지 안되었는지 판단할 때 쓰인다. 매칭되지 않았다면 증가경로의 시작점이 될 수 있다.
int level[MAX_N]; //A정점에 매길 level이다. level을 매길때 B정점은 생략하고 A정점에만 매긴다.
int n, m; //A의 원소의 개수 B의 원소의 개수
vector<int> aMatch, bMatch;
vector<bool> visited;
vector<int> adj[MAX_N]; //그래프가 인접행렬이여도 작동한다.

void bfs()
{
	queue<int> q; //bfs에 사용할 queue를 준비한다.
	for (int i = 0; i < n; i++)
	{
		if (!used[i]) //매칭 되지 않았다면
		{
			level[i] = 0; //증가경로의 시작점이다.
			q.push(i); //시작점을 queue에 밀어 넣는다.
		}
		else level[i] = INF; //매칭 되있는 A정점은 일단 시작점은 아니므로 INF로 level을 매긴다.
	}
	while (!q.empty()) //bfs 시작
	{
		int a = q.front(); 
		q.pop();
		for (int b : adj[a]) //연결되어 있는 b정점 탐색
		{
			if (bMatch[b] != -1 && level[bMatch[b]] == INF) //b정점이 매칭되어있고, 그 매칭되어있는 a정점의 레벨이 정해지지 않았다면 (a정점의 레벨이 정해져있다면 매칭되어있는 건 a정점 자신이다.)
			{
				level[bMatch[b]] = level[a] + 1; //이는 증가경로이므로 level+1을 b와 현재 매칭되어있는 a정점에 매긴다.
				q.push(bMatch[b]); //다음 증가경로를 계속 찾아 나간다.
			}
		}
	}
}

bool dfs(int a) // 매칭 여부를 리턴하는 함수
{
    if(visited[a]) return false; //visited가 체크되어 있다면 매칭 실패
    visited[a] = true; //visited 체크
	for (int b : adj[a])
	{
		if (bMatch[b] == -1 || (!visited[bMatch[b]] && level[bMatch[b]] == level[a] + 1 && dfs(bMatch[b]))) //b가 매칭 되어있지 않거나, 매칭 되었는데 증가경로에 속할경우, dfs로 증가경로를 탐색해가며 경로를 뒤집는다.
		{
			used[a] = true; //매칭 되었으면 사용된 정점이다. 다음에 찾을 증가경로의 시작점이 될 수 없다.
			aMatch[a] = b; //나머지는 일반적인 이분매칭과 같다.
			bMatch[b] = a;
			return true;
		}
	}
	return false;
}

int bipartiteMatch()
{
	aMatch = vector<int>(n, -1);
	bMatch = vector<int>(m, -1);

	int size = 0; //매칭의 최대 크기
	while (1) //더 이상 증가경로를 찾을 수 없어 flow가 0이 되면 탈출한다.
	{
		bfs(); //증가경로를 따라갈 수 있게 level을 매긴다.
		int flow = 0;
		for (int i = 0; i < n; i++)
		{
            visited = vector<bool>(n,false); //visited 배열을 dfs마다 선언해 줘야 한다.
			if (!used[i] && dfs(i)) flow++; //증가경로의 시작점이거나, 바로 매칭이 될 수 있는 지점이면 flow는 1상승한다.
		}
		if (flow == 0) break; //증가경로를 못찾았다. 탈출!
		size += flow; //증가한 flow만큼 매칭의 크기를 증가시킨다.
	}
	return size; //최대매칭 리턴
}

const int LIM = 10001;
int grid[LIM][LIM];

void solve(){
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int N;
    cin>>N;

    n = m = N;

    vector<pair<int,int>> vp;
    vector<bool> rev(N);
    for(int i=0;i<N;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        grid[x1][y1] = i+1;
        grid[x2][y2] = i+1;
        vp.emplace_back(make_pair(x1,y1));
        vp.emplace_back(make_pair(x2,y2));

        if((x1+y1)%2!=0) rev[i] = true;
    }

    for(int i=0;i<2*N;i++){
        if((vp[i].first+vp[i].second)%2==0){
            for(int j=0;j<4;j++){
                int nx = vp[i].first + dx[j];
                int ny = vp[i].second + dy[j];

                if(0<=nx && nx<LIM && 0<=ny && ny<LIM){
                    if(grid[nx][ny]!=0 && grid[nx][ny]!=grid[vp[i].first][vp[i].second]){
                        int u = grid[nx][ny]-1;
                        int v = grid[vp[i].first][vp[i].second]-1;
                        adj[v].emplace_back(u);
                    }
                }
            }
            
        }
    }

    int match = bipartiteMatch();
    int idx = 0;
    if(match == N){
        vector<array<int,2>> ans(N);
        for(int i=0;i<N;i++){
            int op = aMatch[i];
            if(rev[i]) ans[i][1] = i+1;
            else ans[i][0] = i+1;
            if(rev[op]) ans[op][0] = i+1;
            else ans[op][1] = i+1;
        }

        for(auto i : ans) cout<<i[0]<<' '<<i[1]<<'\n';
    }
    else{
        cout<<"impossible";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}