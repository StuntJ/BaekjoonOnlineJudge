#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> V(N);
    for(int i=0;i<N;i++)
        cin>>V[i];

    sort(V.begin(),V.end());

    int ans = 0;
    int l = 0;
    int r = N/2;
    while(l<N/2&&r<N)
    {
        if(V[l]*2<=V[r])
        {
            ans++;
            l++;
        }
        r++;
    }
    cout<<N-ans;
}
