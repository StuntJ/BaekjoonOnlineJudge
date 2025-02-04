#include <bits/stdc++.h>
#define MAX_N 101
#define INF 10000

using namespace std;

char mp[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


struct grid
{
    int u,d,l,r;
};

grid gr; // 일반적인 좌표

bool isInrange(int x, int y)
{
    return 0<x&&x<MAX_N&&0<y&&y<MAX_N;
}

bool isIngrid(int x, int y, grid gr)
{
    return gr.u<=x&&x<=gr.d&&gr.l<=y&&y<=gr.r;
}

int dfsX(int x, int y)
{
    visited[x][y] = true;
    int cnt = 0;
    int blank = 4;
    for(int i=0;i<4;i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(!isIngrid(nx,ny,gr)) continue;
        if(mp[nx][ny]=='X')
        {
            blank--;
            if(!visited[nx][ny])
            {
                cnt+=dfsX(nx,ny);
            }
        }
    }
    return cnt+blank;
}

int dfsP(int x, int y)
{
    //cout<<x<<' '<<y<<'\n';
    visited[x][y] = true;
    int cnt = 0;
    int blank = 4;
    bool out = false;
    for(int i=0;i<4;i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(!isIngrid(nx,ny,gr))
        {
            //cout<<x<<' '<<y<<" not grid\n";
            out = true;
        }
        //cout<<"new : "<<nx<<' '<<ny<<'\n';
        else if(mp[nx][ny] == '\0')
        {
            blank--;
            if(!visited[nx][ny])
            {
                cnt+=dfsP(nx,ny);
            }
        }
    }
    if(out) return -INF;
    else return cnt+blank;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(mp,'\0',sizeof(mp));

    int N;
    cin>>N;



    for(int i=0;i<N;i++)
    {
        int x, y;
        cin>>x>>y;
        mp[x][y] = 'X';
        if(i==0)
        {
            gr.u = x;
            gr.d = x;
            gr.l = y;
            gr.r = y;
        }
        else
        {
            gr.u = min(gr.u,x);
            gr.d = max(gr.d,x);
            gr.l = min(gr.l,y);
            gr.r = max(gr.r,y);

        }
    }
    //cout<<gr.u<<' '<<gr.d<<' '<<gr.l<<' '<<gr.r<<'\n';
    int ans = 0;
    for(int i=1;i<MAX_N;i++)
    {
        for(int j=1;j<MAX_N;j++)
        {
            if(!visited[i][j]&&mp[i][j]=='X')
                ans+=dfsX(i,j);
        }
    }
    /*for(int i=gr.u;i<=gr.d;i++)
    {
        for(int j=gr.l;j<=gr.r;j++)
        {
            cout<<mp[i][j]<<' ';

        }
        cout<<'\n';
    }*/
    //cout<<ans<<'\n';
    for(int i=gr.u;i<=gr.d;i++)
    {
        for(int j=gr.l;j<=gr.r;j++)
        {
            if(!visited[i][j]&&mp[i][j]=='\0')
            {
                int ret = dfsP(i,j);
                if(ret<0) continue;
                //cout<<"sub : "<<i<<' '<<j<<' '<<ret<<'\n';
                ans-=ret;
            }

        }
    }

    cout<<ans;
}
