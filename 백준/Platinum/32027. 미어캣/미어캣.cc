#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<bool> lr(N);
    vector<int> L,R;
    bool tall;
    int M = 0;
    for(int i=0;i<N;i++){
        int x;
        char dir;
        cin>>x>>dir;
        if(dir=='L'){
            lr[i] = false;
            L.push_back(x);
        } 
        else{
            lr[i] = true;
            R.push_back(x);
        } 

        if(x>M){
            tall = lr[i];
            M = x;
        }
    }
    sort(L.begin(),L.end());
    sort(R.begin(),R.end());
    if(tall) R.pop_back();
    else L.pop_back();

    int ans = 0;
    for(int i=0;i<N;i++){
        if(lr[i]!=tall) continue;
        vector<int> v(N);
        int cnt = 1;
        int Lidx = 0;
        int Ridx = 0;
        int maxi = 0;
        for(int j=0;j<i;j++){
            if(lr[j]){
                int t = R[Ridx++];
                v[j] = t;
            }
        }
        for(int j=N-1;j>i;j--){
            if(!lr[j]){
                int t = L[Lidx++];
                v[j] = t;
            }
        }
        maxi = 0;
        for(int j=0;j<i;j++){
            if(!lr[j]){
                while(Lidx<L.size()&&L[Lidx]<maxi){
                    Lidx++;
                }
                if(Lidx<L.size()){
                    cnt++;
                    Lidx++;
                } 
            }
            maxi = max(maxi,v[j]);
            
        }
        maxi = 0;
        for(int j=N-1;j>i;j--){
            if(lr[j]){
                while(Ridx<R.size()&&R[Ridx]<maxi){
                    Ridx++;
                }
                if(Ridx<R.size()){
                    cnt++;
                    Ridx++;
                }
            }
            maxi = max(maxi,v[j]);
        }

        ans = max(ans,cnt);
    }
    cout<<ans;

}