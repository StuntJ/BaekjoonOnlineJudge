#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    int D = 0, P = 0;
    bool op = true;
    while(N--){
        char t;
        cin>>t;
        if(t=='D'&&op){
            D++;
        }
        else{
            if(op)
                P++;
        }
        if(abs(D-P)>=2) op = false;
    }
    cout<<D<<':'<<P;
}