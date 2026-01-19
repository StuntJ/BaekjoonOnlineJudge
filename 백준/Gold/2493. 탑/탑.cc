#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    deque<pair<int,int>> dq;

    for(int i=1;i<=N;i++)
    {
        int height;
        cin>>height;
        dq.push_front(make_pair(height,i));
    }

    stack<pair<int,int>> check;
    vector<int> ans(N+1,0);

    while(!dq.empty())
    {
        check.push(dq.front());
        dq.pop_front();
        while(!check.empty()&&!dq.empty()&&dq.front().first>=check.top().first)
        {
            ans[check.top().second] = dq.front().second;
            check.pop();
        }
    }

    for(int i=1;i<=N;i++) cout<<ans[i]<<' ';
}
