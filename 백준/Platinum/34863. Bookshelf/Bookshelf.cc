#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,L;
    cin>>N>>L;

    vector<int> p(N),w(N);
    for(auto &i : p) cin>>i;
    for(auto &i : w) cin>>i;

    int k,pk;
    cin>>k>>pk;
    k--;

    if(pk+w[k]>L){
        cout<<"NO";
        return 0;
    }

    int b = L-accumulate(w.begin(),w.end(),0);

    vector<int> unmoveableB;
    for(int i=0;i<N;i++){
        if(w[i]>b) unmoveableB.push_back(i);
    }

    if(w[k]>b){ //not moveable
        for(auto it = unmoveableB.begin();it!=unmoveableB.end();it++){
            if(*it==k){
                unmoveableB.erase(it);
                break;
            }
        }
        int idx = 0;
        int sumDown = 0;
        int sumUp = 0;
        while(unmoveableB[idx]<k){
            sumDown += w[unmoveableB[idx]];
            idx++;
        }
        while(idx<unmoveableB.size()){
            sumUp += w[unmoveableB[idx]];
            idx++;
        }
        if(sumDown<=pk && sumUp<=L-pk-w[k]) cout<<"YES";
        else cout<<"NO";
    }
    else{ //moveable
        int i = 0;
        int sumDown = 0;
        int sumUp = 0;
        for(i=0;i<unmoveableB.size()&&sumDown+w[unmoveableB[i]]<=pk;i++){
            sumDown += w[unmoveableB[i]];
        }
        for(i;i<unmoveableB.size();i++) sumUp += w[unmoveableB[i]];
        if(sumDown<=pk && sumUp<=L-pk-w[k]) cout<<"YES";
        else cout<<"NO";
    }
}