#include "bits/stdc++.h"

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str1,str2;
    int a,b;
    cin>>a>>b;
    for(int i=0;i<a;i++) str1 += "1";
    for(int j=0;j<b;j++) str2 +="1";
    
    cout<<stoi(str1)+stoi(str2);
}
