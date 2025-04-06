#include <bits/stdc++.h>

using namespace std;

const string hp = "HAPY";
const string sd = "SAD";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed;
    cout.precision(2);

    string str;
    getline(cin,str);

    int ph = 0, pg = 0;
    for(auto i:str)
    {
        for(auto j:hp)
            if(i==j) ph++;

        for(auto k:sd)
            if(i==k) pg++;
    }

    if(ph==0&&pg==0)
    {
        cout<<50.00<<'\n';
        return 0;
    }

    long double H = (long double)ph/(ph+pg);
    H*=100.0;
    H+=DBL_EPSILON;
    cout<<H;
}
