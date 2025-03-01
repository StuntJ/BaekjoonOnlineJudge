#include <iostream>
#define NMAX 200000000

using namespace std;

int cal(int mid)
{
    int ret = 0;
    while(mid>0)
    {
        ret += mid/5;
        mid/=5;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin>>M;

    int s = 1;
    int e = NMAX;

    while(e>=s)
    {
        int mid = (s+e)/2;
        if(M==cal(mid)+mid)
        {
            cout<<mid*5;
            return 0;
        }
        else if(M>cal(mid)+mid) s = mid+1;
        else e = mid-1;
    }
    cout<<-1;
}
