#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<char>> grid(3,vector<char>(3));

    auto input = [&](){
        cout<<flush;
        for(auto &i : grid) for(auto &j : i) cin>>j;
    };
    
    input();
    int N = 0;
    do{
        cout<<"? R\n";
        input();
        N++;
    }
    while(grid[1][1]!='R');
    int x = 0, y = 0;

    for(int i=0;i<N;i++){
        if(i&1){
            for(int j=N-1;j>=1;j--){
                x--;
                cout<<"? L\n";
                input();
                if(grid[1][1]=='G') goto point;
            }
        }
        else{
            for(int j=0;j<N-1;j++){
                x++;
                cout<<"? R\n";
                input();
                if(grid[1][1]=='G') goto point;
            }
        }
        y++;
        cout<<"? D\n";
        input();
        if(grid[1][1]=='G') goto point;
    }

point:
    while(x>0){
        x--;
        cout<<"? L\n";
        input();
    }
    while(y>0){
        y--;
        cout<<"? U\n";
        input();
    }
    cout<<"!\n";
}