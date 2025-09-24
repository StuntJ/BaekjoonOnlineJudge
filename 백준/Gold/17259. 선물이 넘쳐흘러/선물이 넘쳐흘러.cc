#include <bits/stdc++.h>

using namespace std;

vector<bool> conveyer;
int onGift = 0;
class employee{
public:
    static int giftNum;
    employee(vector<int> &v,int t){
        maxTime = t;
        adj = v;
        timer = 0;
        isGift = 0;
    }
    void findGift(){
        for(int i=0;i<adj.size();i++){
            if(conveyer[adj[i]]){
                conveyer[adj[i]] = false;
                onGift--;
                giftNum++;
                isGift = true;
                timer = 0;
                //cout<<"timer : "<<timer<<' '<<"maxTime : "<<maxTime<<'\n';    
                return;
            }
        }
    }
    void timerGo(){
        if(!isGift){
            findGift();
        }
        else{
            timer++;
            //cout<<"timer : "<<timer<<' '<<"maxTime : "<<maxTime<<'\n';
            if(timer+1==maxTime){
                isGift = false;
                timer = 0;
            }
        }
    }
private:
    bool isGift;
    int timer;
    int maxTime;
    vector<int> adj;
};

int employee::giftNum = 0;

void pushRight(vector<bool> &v){
    if(v.back()) onGift--;
    for(int i=v.size()-2;i>=0;i--) v[i+1] = v[i];
    v[0] = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int B,N,M;
    cin>>B>>N>>M;

    vector<vector<int>> grid(B,vector<int>(B,-1));
    conveyer = vector<bool>(3*B-2);
    int idx = 0;
    for(int i=0;i<B;i++) grid[0][i] = idx++;
    for(int i=1;i<B;i++) grid[i][B-1] = idx++;
    for(int i=B-2;i>=0;i--) grid[B-1][i] = idx++;

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    vector<employee> v;
    for(int i=0;i<N;i++){
        int x,y,t;
        cin>>x>>y>>t;
        vector<int> bp;
        for(int j=0;j<4;j++){
            int nx = x+dx[j];
            int ny = y+dy[j];
            if(0<=nx&&nx<B && 0<=ny&&ny<B){
                if(grid[nx][ny]!=-1)
                    bp.push_back(grid[nx][ny]);
            }
        }
        sort(bp.begin(),bp.end(),greater<int>());
        v.push_back(employee(bp,t));
    }

    while(M>=0||onGift){
        pushRight(conveyer);
        if((M--)>0){
            conveyer[0] = true;
            onGift++;
        }
        /* for(int i=0;i<conveyer.size();i++) cout<<conveyer[i]<<' ';
        cout<<'\n'; */
        for(int i=0;i<v.size();i++){
            v[i].timerGo();
        }
    }
    cout<<v[0].giftNum;
}