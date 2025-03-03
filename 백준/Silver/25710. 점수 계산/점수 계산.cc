#include <bits/stdc++.h>
#define MAX_N 1001

using namespace std;

int chk[MAX_N];

int getSum(int x)
{
    int sum = 0;

    while(x>0)
    {
        sum += x%10;
        x/=10;
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> lst;

    int N;
    cin>>N;

    int maximum = 0;

    for(int i=0;i<N;i++)
    {
        int x;
        cin>>x;
        if(chk[x]==0)
        {
            lst.emplace_back(x);
        }
        chk[x]++;
        if(chk[x]>=2)
        {
            maximum = max(maximum,getSum(x*x));
        }
    }

    int siz = lst.size();



    for(int i=0;i<siz;i++)
    {
        for(int j=i+1;j<siz;j++)
        {
            maximum = max(maximum,getSum(lst[i]*lst[j]));
        }
    }
    cout<<maximum;
}
