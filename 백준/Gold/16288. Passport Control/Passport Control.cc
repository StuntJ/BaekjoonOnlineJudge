#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    cin>>N>>K;

    vector<int> v(N);
    vector<int> chk(N,false);

    for(int i=0;i<N;i++)
    {
        cin>>v[i];
    }

    int ans = 0;

    for(int i=0;i<K;i++)
    {
        int prev = -1;
        for(int j=0;j<N;j++)
        {
            if(chk[j]) continue;
            if(prev<v[j])
            {
                prev = v[j];
                chk[j] = true;
            }
            else continue;
        }
        /*for(auto p: chk)
            cout<<p<<' ';
        cout<<'\n';*/
    }


    bool flag = true;
    for(int i=0;i<N;i++)
    {
        if(!chk[i])
        {
            flag = false;
            break;
        }
    }

    if(!flag) cout<<"NO";
    else cout<<"YES";
}
