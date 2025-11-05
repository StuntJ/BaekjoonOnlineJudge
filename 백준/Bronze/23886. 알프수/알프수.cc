#include <bits/stdc++.h>

using namespace std;

void no(){
    cout<<"NON ALPSOO";
    exit(0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string x;
    cin>>x;

    if(x[0]>=x[1]||x[x.size()-1]>=x[x.size()-2]) no();
    int prevDiff = x[1]-x[0];
    for(int i=1;i<x.size()-1;i++){
        int diff = x[i+1]-x[i];
        if(diff==0) no();
        if(prevDiff*diff>0){
            if(prevDiff!=diff) no();
        }
        prevDiff = diff; 
    }
    cout<<"ALPSOO";
}