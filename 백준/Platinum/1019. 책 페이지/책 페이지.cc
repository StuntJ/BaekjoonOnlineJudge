#include <iostream>
#include <vector>
#include <cmath>
#define NUM_NUM 10

using namespace std;
typedef long long ll;

vector<ll> cntNum;
ll N;

void solve(ll Power,bool isFirstDimension)
{
    ll DIV = pow(NUM_NUM,Power);

    int repeat = N/DIV;
    for(int i=0;i<=repeat-1;i++)
    {
        for(int j=0;j<Power;j++)
            for(int k=0;k<NUM_NUM;k++)
                cntNum[k]+=pow(NUM_NUM,Power-1);

        if(isFirstDimension&&i==0)
            for(int j=0;j<Power;j++)
                cntNum[i]-=pow(NUM_NUM,j);

        else
            cntNum[i]+=DIV;

    }
    int plusNum = N%DIV+1;
    cntNum[repeat]+=plusNum;
    N%=DIV;
    if(Power==0) return;
    solve(Power-1,false);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cntNum.assign(NUM_NUM,0);


    cin>>N;

    ll Power=0;

    ll div = 1;
    while((N/div)>0)
    {
        div*=10;
        Power++;
    }
    Power--;

    solve(Power,true);

    for(auto i : cntNum)
        cout<<i<<' ';
}
