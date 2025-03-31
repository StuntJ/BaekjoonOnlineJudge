#include <iostream>
#include <vector>
#define DIV 10007

using namespace std;

vector<int> cache;

int fillSquare(int n)
{
    if(n<0) return 0;
    int &ret = cache[n];
    if(ret!=-1) return ret;
    if(n==0) return 1;
    return ret = (fillSquare(n-1)%DIV+fillSquare(n-2)%DIV)%DIV;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    cache.assign(n+1,-1);

    cout<<fillSquare(n);
}
