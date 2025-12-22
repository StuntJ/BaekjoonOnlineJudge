#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> S;
vector<int> cache;

int lis(int start)
{
    int &ret = cache[start+1];
    if(ret!=-1) return ret;
    ret = 0;
    for(int next=start+1;next<N;next++)
        if(start==-1||S[start]<S[next])
            ret = max(ret,1+lis(next));
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    cache.assign(N+1,-1);

    for(int i=0;i<N;i++)
    {
        int data;
        cin>>data;
        S.emplace_back(data);
    }

    cout<<lis(-1);
}
