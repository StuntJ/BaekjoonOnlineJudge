#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    int K,Q;
    cin>>N>>K>>Q;

    while(Q--){
        ll a,b;
        cin>>a>>b;
        if(K==1){
            cout<<abs(a-b)<<'\n';   
            continue;
        }
        vector<int> va,vb;
        while(a>0){
            va.push_back(a);
            a = (a+(K-2))/K;
        }
        while(b>0){
            vb.push_back(b);
            b = (b+(K-2))/K;
        }

        ll aidx=-1, bidx=-1;
        for(int i=0;i<va.size();i++){
            for(int j=0;j<vb.size();j++){
                if(va[i]==vb[j]){
                    aidx = i;
                    bidx = j;
                    break;
                }
            }
            if(aidx!=-1) break;
        }

        cout<<aidx+bidx<<'\n';
    }
}