#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tot;
    cin>>tot;
    int n,m;
    cin>>n>>m;

    vector<int> A(n),B(m);

    for(auto &i : A) cin>>i;
    for(auto &i : B) cin>>i;

    map<int,int> mA,mB;
    int totA = accumulate(A.begin(),A.end(),0);
    int totB = accumulate(B.begin(),B.end(),0);
    mA[totA]++;
    mB[totB]++;
    for(int i=0;i<n;i++){
        int sum = A[i];
        mA[sum]++;
        int rep = n-2;
        int j = (i+1)%n;
        while(rep--){
            sum += A[j];
            mA[sum]++;
            j = (j+1)%n;
        }
    }

    for(int i=0;i<m;i++){
        int sum = B[i];
        mB[sum]++;
        int rep = m-2;
        int j = (i+1)%m;
        while(rep--){
            sum += B[j];
            mB[sum]++;
            j = (j+1)%m;
        }
    }

    ll ans = 0;
    mA[0] = mB[0] = 1;
    for(int i=0;i<=tot;i++){
        ans += mA[i]*(ll)mB[tot-i];
    }
    cout<<ans;
}