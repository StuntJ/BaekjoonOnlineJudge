#include <bits/stdc++.h>

using namespace std;

const int LIM = 2000001;

bool prime[LIM];

void getPrime(){
    prime[0] = prime[1] = true;
    for(int i=2;i*i<LIM;i++){
        for(int j=i*i;j<LIM;j+=i){
            prime[j] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    getPrime();

    int N,M;
    cin>>N>>M;

    bool flag = false;
    vector<int> v;
    for(int i=1;i<LIM;i++){
        v.clear();
        for(int j=i;j<LIM;j+=M){
            if(!prime[j]) break;
            v.emplace_back(j);
        }
        if(v.size()>=N){
            flag = true;
            break;
        }
    }
    if(flag){
        for(int i=0;i<N;i++) cout<<v[i]<<' ';
    }
    else cout<<-1;
}