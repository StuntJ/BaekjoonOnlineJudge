#include <bits/stdc++.h>
#define MAX_K 100001

using namespace std;

int dp[MAX_K];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    cin>>N>>K;

    vector<pair<int,int>> info(N);

    for(int i=0;i<N;i++) cin>>info[i].first>>info[i].second;

    for(int i=0;i<N;i++)
    {
        for(int j=K;j>=info[i].first;j--)
        {
            dp[j] = max(dp[j],info[i].second+dp[j-info[i].first]);
        }
    }

    cout<<*max_element(dp,dp+MAX_K);
}
