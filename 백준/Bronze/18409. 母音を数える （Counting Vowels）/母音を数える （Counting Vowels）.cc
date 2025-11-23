#include <bits/stdc++.h>

using namespace std;

int main(){
    string v = "aeiou";
    int N;
    cin>>N;
    string str;
    cin>>str;
    int cnt = 0;
    for(auto i : str){
        for(auto j : v){
            if(i==j){
                cnt++;
                break;
            }
        }
    }
    cout<<cnt;
}