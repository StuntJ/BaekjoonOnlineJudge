#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    cin>>N>>K;

    vector<int> arr;
    vector<bool> chk(N+1,false);

    for(int i=1;i<=N;i++)
    {
        int num;
        cin>>num;
        if(num>N)
        {
            cout<<false;
            return 0;
        }
        chk[num] = true;
        arr.emplace_back(num);
    }

    sort(arr.begin(),arr.end());

    bool possible = true;

    for(int i=1;i<N;i++)
    {
        bool flag = false;
        if(arr[i-1] == arr[i])
            flag = true;

        if(flag)
        {
            int number = arr[i];
            while(number<=N)
            {
                number+=K;
                if(chk[number]==false) break;
            }

            if(number>N)
            {
                possible = false;
                break;
            }
            chk[number] = true;
        }
    }

    cout<<possible;
}
