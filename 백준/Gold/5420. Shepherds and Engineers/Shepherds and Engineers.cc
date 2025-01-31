#include <bits/stdc++.h>
#define MAX_N 2000001

using namespace std;

int isNotPrime(int num)
{
    if(num<3) return 0;
    if(num<5) return 1;

    for(int i=3;i*i<=num;i++)
        if(num%i==0) return num/i;
    if(num%2==0) return 2;
    return 1;
}

int solve(int mid, int b)
{
    int here = mid;
    while(b>0) //repeat b
    {

        int next = here;
        while(next-isNotPrime(next)<here) next++;
        here = next;
        b--;
    }
    return here;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    /*for(int i=1;i<1000;i++)
        cout<<"i : "<<i<<' '<<isNotPrime[i]<<'\n';*/


    int T;
    cin>>T;

    for(int t=0;t<T;t++)
    {
        int s,b;
        cin>>s>>b;
        int ans = solve(s,b);
        cout<<ans<<'\n';
    }
}
