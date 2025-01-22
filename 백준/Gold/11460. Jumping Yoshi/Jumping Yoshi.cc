#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true)
    {
        int N;
        cin>>N;
        if(N==0) return 0;

        vector<int> adj[N];
        int pebbles[N];
        bool visited[N];
        memset(visited,false,sizeof(visited));

        for(int i=0;i<N;i++)
        {
            int ai;
            cin>>ai;
            pebbles[i] = ai;
            if(ai == 0)
            {
                adj[i].emplace_back(i);
                continue;
            }
            if(i+ai<N) adj[i+ai].emplace_back(i);
            if(i-ai>=0) adj[i-ai].emplace_back(i);
        }

        /*for(int i=0;i<N;i++)
        {
            cout<<"i : "<<i<<"  ";
            for(int j=0;j<adj[i].size();j++)
            {
                cout<<adj[i][j]<<' ';
            }
            cout<<'\n';
        }*/

        queue<int> q;
        q.push(0);
        visited[0] = true;
        int maxidx = 0;
        while(!q.empty())
        {
            int here = q.front();
            q.pop();
            maxidx = max(maxidx,here);

            if(here+pebbles[here]<N)
            {
                for(auto there : adj[here+pebbles[here]])
                {
                    if(!visited[there]&&here+pebbles[here]<=there)
                    {
                        visited[there] = true;
                        q.push(there);
                    }
                }
            }
            if(here-pebbles[here]>=0)
            {
                for(auto there : adj[here-pebbles[here]])
                {
                    if(!visited[there]&&here-pebbles[here]>=there)
                    {
                        visited[there] = true;
                        q.push(there);
                    }
                }
            }
        }
        cout<<maxidx<<'\n';
    }
}
