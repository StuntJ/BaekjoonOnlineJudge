#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ans;
string str;
ll N;
bool flag = false;

void solve(int th_len,int here, int N_size)
{
    if(here==th_len)
    {
        //cout<<str<<'\n';
        if(stoll(str)<=N) ans++;
        else flag = true;
        return;
    }

    if(here==0)
    {
        for(int i=1;i<10;i++)
        {
            str[here] = str[N_size-here-1] = i+'0';
            solve(th_len,here+1,N_size);
            if(flag) return;
        }
    }
    else
    {
        for(int i=0;i<10;i++)
        {
            str[here] = str[N_size-here-1] = i+'0';
            solve(th_len,here+1,N_size);
            if(flag) return;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin>>N;

    int N_size = to_string(N).size();

    for(int i=1;i<N_size;i++)
    {
        int temp = 9;
        int h_len = (i+1)/2;
        for(int j=1;j<h_len;j++)
        {
            temp*=10;
        }
        ans+=temp;
    }

    int th_len = (N_size+1)/2;
    str.resize(N_size);
    solve(th_len,0,N_size);
    cout<<ans;
}
