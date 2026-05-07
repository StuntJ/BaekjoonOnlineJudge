#include <string>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    vector<int> answer(2);
    int minNum = 0;
    
    vector<vector<int>> grid(m,vector<int>(n,1e6));
    vector<vector<int>> mn(m,vector<int>(n,0));
    vector<vector<int>> mn2(m,vector<int>(n,0));
    
    for(int i=0;i<drops.size();i++){
        int x = drops[i][0];
        int y = drops[i][1];
        
        grid[x][y] = i+1;
    }
    
    for(int i=0;i<m;i++){
        deque<int> dq;
        for(int j=0;j<n;j++){
            while(!dq.empty()&&dq.front()<=j-w) dq.pop_front();
            while(!dq.empty()&&grid[i][dq.back()]>grid[i][j]){
                dq.pop_back();
            }
            dq.push_back(j);
            if(j-w+1>=0) mn[i][j-w+1] = grid[i][dq.front()];
        }
    }
    
    for(int j=0;j+w<=n;j++){
        deque<int> dq;
        for(int i=0;i<m;i++){
            while(!dq.empty()&&dq.front()<=i-h) dq.pop_front();
            while(!dq.empty()&&mn[dq.back()][j]>mn[i][j]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i-h+1>=0) mn2[i-h+1][j] = mn[dq.front()][j];
        }
    }
    
    int mx = 0;
    for(int i=0;i+h<=m;i++){
        for(int j=0;j+w<=n;j++){
            if(mn2[i][j]>mx){
                mx = mn2[i][j];
                answer[0] = i;
                answer[1] = j;
            }
        }
    }
    
    return answer;
}