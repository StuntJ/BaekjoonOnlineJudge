#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<vector<int>> arr(N,vector<int>(N));

    for(auto &i : arr) for(auto &j : i) cin>>j;

    int curX = N/2, curY = N/2;

    int dx[4] = {0,1,0,-1};
    int dy[4] = {-1,0,1,0};

    auto rotate = [&](pair<int,int> &a)->pair<int,int>{ 
        int ni = a.first*0+a.second*-1;
        int nj = a.first*1+a.second*0;
        return make_pair(ni,nj);
    };

    map<pair<int,int>,int> mp;
    mp.insert({{-2,-1},2});
    mp.insert({{-1,-2},10});
    mp.insert({{-1,-1},7});
    mp.insert({{-1,0},1});
    mp.insert({{0,-3},5});
    mp.insert({{1,-2},10});
    mp.insert({{1,-1},7});
    mp.insert({{1,0},1});
    mp.insert({{2,-1},2});
    int ans = 0;

    auto isInrange = [&](int x, int y){
        return (0<=x&&x<N && 0<=y&&y<N);
    };

    auto f = [&](int j){ //curX,curY에서 j방향으로 이동할때 구현
        int here = arr[curX+dx[j]][curY+dy[j]];
        int temp = 0;
        for(auto i : mp){
            pair<int,int> a = i.first;
            for(int k=0;k<j;k++){
                a = rotate(a);
            }
            int nx = curX + a.first;
            int ny = curY + a.second;
            int rate = i.second;
            int add = here*rate/100;
            if(isInrange(nx,ny)){
                arr[nx][ny]+=add;
            }
            else{
                ans += add;
            }
            temp+=add;
        }
        int nx = curX + 2*dx[j];
        int ny = curY + 2*dy[j];
        if(isInrange(nx,ny)){
            arr[nx][ny] += here-temp;
        }
        else ans += here-temp;
        arr[curX+dx[j]][curY+dy[j]] = 0;
    };
    
    int counter = 0;
    int counterUP = 0;
    for(int i=0;i<(N-1)/2;i++){
        for(int j=0;j<4;j++){
            if(!((counterUP++)&1)) counter++;
            for(int k=0;k<counter;k++){
                f(j);
                curX += dx[j];
                curY += dy[j];
            }
        }
    }

    for(int k=0;k<counter;k++){
        f(0);
        curX += dx[0];
        curY += dy[0];
    }
    cout<<ans;
}