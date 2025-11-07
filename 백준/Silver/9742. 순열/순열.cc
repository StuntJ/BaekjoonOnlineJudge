#include <bits/stdc++.h>

using namespace std;

int fact[11];
void initFact(){
    fact[0] = 1;
    for(int i=1;i<11;i++){
        fact[i] = fact[i-1]*i;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    initFact();

    string str;
    int N;
    while(cin>>str>>N){
        string per = str;

        if(N>fact[str.size()]){
            cout<<str<<' '<<N<<" = "<<"No permutation\n";
        }
        else{
            int cnt = 1;
            do{
                if(cnt==N) break;
                cnt++;
            }while(next_permutation(per.begin(),per.end()));

            cout<<str<<' '<<N<<" = "<<per<<'\n';
        }
    }
}