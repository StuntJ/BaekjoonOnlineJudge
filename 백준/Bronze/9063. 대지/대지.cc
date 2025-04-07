#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    const int INF= 100000;
    int xM = -INF;
    int xm = INF;
    int yM = -INF;
    int ym = INF;

    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int x,y;
        cin>>x>>y;
        xM= max(xM,x);
        xm = min(xm,x);
        yM = max(yM,y);
        ym = min(ym,y);
    }
    cout<<(xM-xm)*(yM-ym);
}