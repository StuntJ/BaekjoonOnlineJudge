#include <bits/stdc++.h>
#define E_NUM 4
#define E_MAX 31
#define E_POS 5

using namespace std;


int cache[2][E_MAX][E_MAX][E_MAX][E_MAX];
int react[E_POS][E_NUM] =
{
    2,1,0,2,
    1,1,1,1,
    0,0,2,1,
    0,3,0,0,
    1,0,0,1
};

int solve(vector<int> &arr,int depth)
{
    int &ret = cache[depth%2][arr[0]][arr[1]][arr[2]][arr[3]];
    if(ret!=-1) return ret;

    if(depth%2) //odd
    {
        int pos = 1;
        for(int i=0;i<E_POS;i++)
        {
            bool flag = true;
            for(int j=0;j<E_NUM;j++)
            {
                if(arr[j] - react[i][j]<0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                for(int j=0;j<E_NUM;j++)
                    arr[j]-=react[i][j];

                /*for(auto k : arr)
                    cout<<k<<' ';
                cout<<'\n';*/

                if(!solve(arr,depth+1))
                {
                    for(int j=0;j<E_NUM;j++)
                        arr[j]+=react[i][j];
                    pos = 0;
                    break;
                }

                for(int j=0;j<E_NUM;j++)
                    arr[j]+=react[i][j];
            }
        }

        return ret = pos;
    }
    else //even
    {
        for(int i=0;i<E_POS;i++)
        {
            bool flag = true;
            for(int j=0;j<E_NUM;j++)
            {
                if(arr[j] - react[i][j]<0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                for(int j=0;j<E_NUM;j++)
                    arr[j]-=react[i][j];

                /*for(auto k : arr)
                    cout<<k<<' ';
                cout<<'\n';*/

                if(solve(arr,depth+1))
                {
                    for(int j=0;j<E_NUM;j++)
                        arr[j]+=react[i][j];
                    return ret = 1;
                }


                for(int j=0;j<E_NUM;j++)
                    arr[j]+=react[i][j];
            }

        }
        return ret = 0;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*for(int i=0;i<E_POS;i++)
    {
        for(int j=0;j<E_NUM;j++)
        {
           cout<<react[i][j]<<' ';
        }
        cout<<'\n';
    }*/


    int T;
    cin>>T;

    for(int t=0;t<T;t++)
    {
        memset(cache,-1,sizeof(cache));

        vector<int> firstData(E_NUM);

        for(int i=0;i<E_NUM;i++)
            cin>>firstData[i];



        int ans = solve(firstData,0);
        if(ans) cout<<"Patrick"<<'\n';
        else cout<<"Roland"<<'\n';

    }
}
