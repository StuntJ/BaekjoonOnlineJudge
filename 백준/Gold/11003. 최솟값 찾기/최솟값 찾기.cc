#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,L;
    cin>>N>>L;

    vector<int> v(N);
    for(auto &i : v) cin>>i;
    
    deque<pii> dq;

    for(int i=0;i<N;i++){
        while(!dq.empty()&&dq.back().first>v[i]){
            dq.pop_back();
        }
        while(!dq.empty()&&dq.front().second<=i-L){
            dq.pop_front();
        }

        dq.push_back({v[i],i});
        cout<<dq.front().first<<' ';
    }
}