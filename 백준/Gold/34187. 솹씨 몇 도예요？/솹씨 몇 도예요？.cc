#include <bits/stdc++.h>

using namespace std;

void input(string &str){
    str.clear();
    cout<<flush;
    cin>>str;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;

    int s = 0, e = 2025;
    while(true){
        int mid = (s+e)/2;
        cout<<"? "<<mid<<'\n';
        input(str);
        if(str=="SUAPC!"){
            cout<<"! "<<mid<<'\n';
            return 0;
        }
        else if(str=="Cold"){
            s = mid;
            e= (mid+e)/2;
        }
        else if(str=="Hot"){
            s=(s+mid)/2;
            e = mid-1;
        }
    }
}