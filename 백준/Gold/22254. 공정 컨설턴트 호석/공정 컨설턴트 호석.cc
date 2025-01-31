#include <bits/stdc++.h>

using namespace std;

int cal(vector<int> &T, int mid)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<mid;i++)
        pq.push(0);

    int maximum = 0;
    for(auto makingTime : T)
    {
        int pi = pq.top();
        //cout<<pi<<'\n';
        pq.pop();
        pi+=makingTime;
        maximum = max(maximum,pi);
        pq.push(pi);
    }
    return maximum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,X;
    cin>>N>>X;

    vector<int> T(N);
    for(int i=0;i<N;i++)
        cin>>T[i];

    int s = 1;
    int e = N;
    int ans;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(cal(T,mid)<=X)
        {
            ans = mid;
            e = mid-1;
        }
        else s = mid+1;
    }
    cout<<ans;
}
