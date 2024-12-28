#include <bits/stdc++.h>
#define DIV 1000000009
#define HERE_NUM 3
#define MAX_N 33334

using namespace std;
typedef long long ll;

int N;
ll cache[HERE_NUM][MAX_N];

ll solve(int stat, int here)
{
    if(here==N)
    {
        if(stat==0) return 1;
        else return 0;
    }
    ll &ret = cache[stat][here];
    if(ret!=-1) return ret;
    ret = 0;

    for(int i=0;i<3;i++)
    {
        if(here==0&&i==0) continue;
        int there_stat = (stat+i)%3;
        ret = (ret%DIV + solve(there_stat,here+1)%DIV)%DIV;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cache,-1,sizeof(cache));

    cin>>N;

    cout<<solve(0,0);
}
