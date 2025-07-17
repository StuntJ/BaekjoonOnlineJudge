#include <bits/stdc++.h>
#define MAX_N 41

using namespace std;
typedef long long ll;

int arr[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;

    bool ex = false;

    for(int i=0;i<N;i++)
    {
        int x;
        cin>>x;
        arr[x]++;
        if(arr[x]>2) ex = true;
    }
    if(ex)
    {
        cout<<0;
        return 0;
    }

    int cnt = 0;
    int idx = 0;
    ll ans = 2;
    if(arr[idx]==0)
    {
        cout<<0;
        return 0;
    }
    else if(arr[idx]==1) cnt+=1;
    else cnt+=2;

    idx++;
    while(cnt<N)
    {
        int num = arr[idx];
        if(num==0)
        {
            cout<<0;
            return 0;
        }
        else if(num==1)
        {
            if(arr[idx-1]==2) ans*=2;
            else if(arr[idx-1]==1) ans*=1;
            cnt+=1;
        }
        else
        {
            if(arr[idx-1]==2) ans*=2;
            else
            {
                cout<<0;
                return 0;
            }
            cnt+=2;
        }
        idx++;
    }
    cout<<ans;
}
