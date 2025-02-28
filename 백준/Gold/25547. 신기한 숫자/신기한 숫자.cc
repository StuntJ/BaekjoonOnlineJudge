#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A,B;
    cin>>A>>B;
    if(B%A!=0)
    {
        cout<<0;
    }
    else
    {
        int ob = B/A;
        int cnt = 0;
        for(int i=1;i*i<=ob;i++)
        {
            if(ob%i==0)
            {
                if(i*i==ob) cnt++;
                else cnt+=2;
            }
        }
        cout<<cnt;
    }
}
