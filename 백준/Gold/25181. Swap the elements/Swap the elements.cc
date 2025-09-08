#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<int> A(N),B;
    for(auto &i : A) cin>>i;
    B = A;
    
    for(int i=0;i<N;i++){
        if(B[i]!=A[i]) continue;
        bool flag = false;
        for(int j=0;j<N;j++){
            if(i==j) continue;
            if(A[i]!=B[j] && A[j]!=B[i]){
                flag = true;
                swap(B[i],B[j]);
                break;
            }
        }
        /* for(auto j : B) cout<<j<<' ';
        cout<<'\n'; */
        if(!flag){
            cout<<-1;
            return 0;
        }
    }

    for(auto i : B) cout<<i<<' ';
}