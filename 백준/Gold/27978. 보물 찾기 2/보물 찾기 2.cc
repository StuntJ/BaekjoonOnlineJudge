#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int H,W;
vector<vector<char>> board;
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

struct pq_data
{
    int x;
    int y;
    int cost;

    bool operator < (const pq_data &rhs) const
    {
        return cost>rhs.cost;
    }
};

bool isInrange(int x, int y)
{
    return 0<=x&&x<H && 0<=y&&y<W && board[x][y]!='#';
}

vector<vector<int>> dijkstra(pair<int,int> src)
{
    priority_queue<pq_data> pq;
    pq.push({src.first,src.second,0});
    vector<vector<int>> dist(H,vector<int>(W,INF));
    dist[src.first][src.second] = 0;
    while(!pq.empty())
    {
        pair<int,int> here = make_pair(pq.top().x,pq.top().y);
        int cost = pq.top().cost;
        pq.pop();
        if(dist[here.first][here.second]<cost) continue;
        for(int i=0;i<8;i++)
        {
            int nx = here.first + dx[i];
            int ny = here.second + dy[i];
            if(isInrange(nx,ny))
            {
                int nextDist = cost;
                if(dy[i]!=1) nextDist++;
                if(dist[nx][ny]>nextDist)
                {
                    dist[nx][ny] = nextDist;
                    pq.push({nx,ny,nextDist});
                }
            }
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>H>>W;

    board.resize(H,vector<char>(W));

    pair<int,int> src;
    pair<int,int> tresure;

    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            cin>>board[i][j];
            if(board[i][j]=='K') src = make_pair(i,j);
            if(board[i][j]=='*') tresure = make_pair(i,j);
        }
    }

    vector<vector<int>> dist = dijkstra(src);

    int ans = dist[tresure.first][tresure.second];
    if(ans==INF) cout<<-1;
    else cout<<dist[tresure.first][tresure.second];
}
