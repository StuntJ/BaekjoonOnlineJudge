#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<int> grid(N+1);
    for(auto &i : grid) cin>>i;

    int x;
    cin>>x;

    int numOne = 0;

    for(auto i : grid) if(i==1) numOne++;

    if(numOne>0){
        if(numOne>=3){
            cout<<"NO";
            return 0;
        }
        else if(numOne==2){
            int numOneIdx = 0;
            for(int i=0;i<=N;i++){
                if(grid[i]==1){
                    numOneIdx = i;
                    break;
                }
            }
            if(numOneIdx+x<=N && grid[numOneIdx+x]==1){
                cout<<"YES\n";
                cout<<numOneIdx<<' '<<numOneIdx+x;
                return 0;
            }
            else{
                cout<<"NO";
                return 0;
            }
        }
        else{
            int numOneIdx = 0;
            for(int i=0;i<=N;i++){
                if(grid[i]==1) numOneIdx = i; 
            }
            if(numOneIdx+x<=N && grid[numOneIdx+x]!=0){
                cout<<"YES\n";
                cout<<numOneIdx<<' '<<numOneIdx+x;
                return 0;
            }
            
            for(int i=0;i+x<=N;i++){
                if(grid[i]>2 && grid[i+x]==1){
                    cout<<"YES\n";
                    cout<<i<<' '<<i+x;
                    return 0;
                }
            }
            cout<<"NO";
            return 0;
            
        }
    }
    else{
        for(int i=0;i+x<=N;i++){
            if(grid[i]>2 && grid[i+x]>0){
                cout<<"YES\n";
                cout<<i<<' '<<i+x;
                return 0;
            }
        }
        cout<<"NO";
    }
}