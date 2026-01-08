#include <bits/stdc++.h>

using namespace std;

struct inst{
    int num = -1;
    int nextState = -1;
    int nextDir = -1;
};

struct State{
    int bit;
    int hereState;
    int here;
};

int fpow(int n, int p){
    if(p==0) return 1;
    int temp = fpow(n,p/2);
    int ret = temp*temp;
    if(p&1) return ret*n;
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    char initStateCh;
    cin>>initStateCh;

    int initState = initStateCh-'A';

    int N,L;
    cin>>N>>L;

    vector<vector<inst>> mp(16,vector<inst>(2));

    for(int i=0;i<N;i++){
        char state;
        int ori;
        int ch;
        char nextState;
        int nextDir;

        cin>>state>>ori>>ch>>nextState>>nextDir;

        mp[state-'A'][ori] = {ch,nextState-'A',nextDir};
    }

    string bit;
    cin>>bit;
    
    reverse(bit.begin(),bit.end());
    
    int bitint = 0;
    for(int i=0;i<bit.size();i++){
        if(bit[i]=='1') bitint += fpow(2,i);
    }

    //reverse(bit.begin(),bit.end());

    State firstState = {bitint,initState,bit.size()-1};
    vector<vector<vector<bool>>> visited(1<<L,vector<vector<bool>>(16,vector<bool>(L)));
    visited[bitint][initState][L-1] = true;
    queue<State> q;
    q.push(firstState);

    while(!q.empty()){
        int herebit = q.front().bit;
        int hereState = q.front().hereState;
        int here = q.front().here;

        //cout<<bitset<4>(herebit)<<' '<<hereState<<' '<<here<<'\n';

        //int k = ((herebit&(1<<here))!=0);
        inst instHere = mp[hereState][(herebit&(1<<here))!=0];
        if(instHere.num==-1){
            cout<<"STOP";
            return 0;
        }
        else{
            int nextBit;
            if(instHere.num){
                nextBit = (herebit|(1<<here));
            }
            else{
                nextBit = (herebit & ~(1<<here));
            }

            int next = here - instHere.nextDir;
            if(next<0 || next>=L){
                cout<<"STOP";
                return 0;
            }
            if(!visited[nextBit][instHere.nextState][next]){
                visited[nextBit][instHere.nextState][next] = true;
                q.push({nextBit,instHere.nextState,next});
            }
        }
        q.pop();
    }
    cout<<"CONTINUE";
}