#include <bits/stdc++.h>

using namespace std;

int N,A,B;

struct q_data
{
    int x;
    int t;
};

bool isInrange(int x)
{
    return 1<=x&&x<=N;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>A>>B;

    vector<vector<bool>> visitedA(N+1,vector<bool>(20,false));
    vector<vector<bool>> visitedB(N+1,vector<bool>(20,false));

    queue<q_data> qa;
    qa.push({A,0});
    visitedA[A][0] = true;
    while(!qa.empty())
    {
        int here = qa.front().x;
        int t = qa.front().t;
        qa.pop();


        int jump = pow(2,t);

        if(here+jump<=N && !visitedA[here+jump][t+1])
        {
            qa.push({here+jump,t+1});
            visitedA[here+jump][t+1] = true;
        }
        if(here-jump>0 && !visitedA[here-jump][t+1])
        {
            qa.push({here-jump,t+1});
            visitedA[here-jump][t+1] = true;
        }
    }
    queue<q_data> qb;
    qb.push({B,0});
    visitedB[B][0] = true;
    while(!qb.empty())
    {
        int here = qb.front().x;
        int t = qb.front().t;
        qb.pop();

        int jump = pow(2,t);

        if(here+jump<=N && !visitedB[here+jump][t+1])
        {
            qb.push({here+jump,t+1});
            visitedB[here+jump][t+1] = true;
        }
        if(here-jump>0 && !visitedB[here-jump][t+1])
        {
            qb.push({here-jump,t+1});
            visitedB[here-jump][t+1] = true;
        }
    }

    for(int i=0;i<20;i++)
    {
        for(int j=1;j<N;j++)
        {
            if(visitedA[j][i]&&visitedB[j][i])
            {
                cout<<i;
                return 0;
            }
        }
    }
    cout<<-1;
}
