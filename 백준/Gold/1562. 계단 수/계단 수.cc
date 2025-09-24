#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#define DIV 1000000000
#define NUM_OF_STAT 10

using namespace std;

int N;
int cache[1<<NUM_OF_STAT][101][NUM_OF_STAT];

int solve(int n,int stat,int hereNum)
{

    if(n==N)
    {
        if(stat==(1<<NUM_OF_STAT)-1)
        {
            //cout<<"n : "<<n<<" stat : "<<bitset<10>(stat)<< " ret : "<<1<<" hereNum : "<<hereNum<<endl;
            return 1;
        }
        else
        {
            //cout<<"n : "<<n<<" stat : "<<bitset<10>(stat)<< " ret : "<<0<<" hereNum : "<<hereNum<<endl;
            return 0;
        }
    }

    int &ret = cache[stat][n][hereNum];
    if(ret!=-1)
    {
        //cout<<"n : "<<n<<" stat : "<<bitset<10>(stat)<< " ret : "<<ret<<" hereNum : "<<hereNum<<endl;
        return ret;
    }

    ret = 0;
    if(n==0)
    {
        for(int i=1;i<NUM_OF_STAT;i++)
        {
            ret += solve(n+1,stat|(1<<i),i)%DIV;
            ret%=DIV;
        }
    }
    else
    {
        if(hereNum>0)
        {
            ret += solve(n+1,stat|(1<<(hereNum-1)),hereNum-1)%DIV;
            ret%=DIV;
        }
        if(hereNum<NUM_OF_STAT-1)
        {
            ret += solve(n+1,stat|(1<<(hereNum+1)),hereNum+1)%DIV;
            ret%=DIV;
        }
    }
    //cout<<"n : "<<n<<" stat : "<<bitset<10>(stat)<< " ret : "<<ret<<" hereNum : "<<hereNum<<endl;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&cache[0][0][0],&cache[(1<<NUM_OF_STAT)-1][101-1][NUM_OF_STAT],-1);

    cin>>N;

    cout<<solve(0,0,0);
}
