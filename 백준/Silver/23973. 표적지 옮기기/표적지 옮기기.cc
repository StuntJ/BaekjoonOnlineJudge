#include <iostream>
#include <vector>
#define SCORE_PAPER_SIZE 19
#define MAX_SCORE 10

using namespace std;

vector<vector<int>> scorePaper(SCORE_PAPER_SIZE,vector<int>(SCORE_PAPER_SIZE));

void drawScorePaper(int x,int y, int N, int num)
{
    if(num>MAX_SCORE) return;

    for(int i=x;i<x+N;i++)
    {
        scorePaper[x][i] = scorePaper[x+N-1][i] =num;
        scorePaper[i][y] = scorePaper[i][y+N-1] =num;
    }
    drawScorePaper(x+1,y+1,N-2,++num);
}

pair<int,int> returnStart(const int x, const int y, vector<vector<char>> &shotPaper)
{
    int start_x = x-(MAX_SCORE-1);
    int start_y = y-(MAX_SCORE-1);

    if(start_x>=0&&start_y>=0) return make_pair(start_x,start_y);
    else if(start_x>=0&&start_y<0) return make_pair(start_x,0);
    else if(start_x<0&&start_y>=0) return make_pair(0,start_y);
    else make_pair(0,0);
}

pair<int,int> returnFinish(const int x, const int y, vector<vector<char>> &shotPaper)
{
    int end_x = x+(MAX_SCORE-1);
    int end_y = y+(MAX_SCORE-1);
    int xlim = shotPaper.size();
    int ylim = shotPaper[0].size();

    if(end_x<xlim&&end_y<ylim) return make_pair(end_x,end_y);
    else if(end_x<xlim&&end_y>=ylim) return make_pair(end_x,ylim-1);
    else if(end_x>=xlim&&end_y<ylim) return make_pair(xlim-1,end_y);
    else make_pair(xlim-1,ylim-1);
}

bool paperCheck(const int x, const int y, vector<vector<char>> &shotPaper)
{
    vector<int> check(MAX_SCORE+1,0);
    pair<int,int> start = returnStart(x,y,shotPaper);
    pair<int,int> finish = returnFinish(x,y,shotPaper);

    int xReform = MAX_SCORE-1-x;
    int yReform = MAX_SCORE-1-y;

    for(int i=start.first;i<=finish.first;i++)
        for(int j=start.second;j<=finish.second;j++)
            if(shotPaper[i][j]=='1')
                check[scorePaper[i+xReform][j+yReform]]++;


    for(int i=1;i<=MAX_SCORE;i++)
        if(check[i]!=1) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    drawScorePaper(0,0,SCORE_PAPER_SIZE,1);

    int N,M;
    cin>>N>>M;

    vector<vector<char>> shotPaper(N,vector<char>(M));

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>shotPaper[i][j];

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(shotPaper[i][j]=='1')
            {
                if(paperCheck(i,j,shotPaper))
                {
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }
    }
    cout<<-1;
}
