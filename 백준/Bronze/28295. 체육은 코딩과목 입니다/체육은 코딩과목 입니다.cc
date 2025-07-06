#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dir =0;
    for(int i=0;i<10;i++)
    {
        int x;
        cin>>x;
        dir+=x;
    }
    switch(dir%4){
        case 0:
        cout<<"N"<<'\n';
        break;
        case 1:
        cout<<"E"<<'\n';
        break;
        case 2:
        cout<<"S"<<'\n';
        break;
        case 3:
        cout<<"W"<<'\n';
        break;
    }
}