#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int N;
    cin>>N;

    vector<int> v(N+1);
    for(int i=1;i<=N;i++) cin>>v[i];

    list<deque<pair<int,int>>> lst;
    list<deque<pair<int,int>>>::iterator it;
    vector<bool> visited(N+1);

    function<void(int)> dfs = [&](int here){
        visited[here] = true;
        it->push_back({here,v[here]});
        int nxt = v[here];

        if(!visited[nxt]){
            dfs(nxt);
        }
    };

    for(int i=1;i<=N;i++){
        if(!visited[i]){
            lst.push_back(deque<pair<int,int>>());
            it = prev(lst.end());
            dfs(i);
        }
    }

    lst.sort([&](deque<pair<int,int>> &a, deque<pair<int,int>> &b){
        bool aIsOdd = (a.size()&1);
        bool bIsOdd = (b.size()&1);

        if(aIsOdd!=bIsOdd){
            return aIsOdd;
        }

        return false;
    });

    int cnt = 0;
    for(auto i : lst) if(i.size()&1) cnt++;

    it = lst.begin();
    bool flag = false;
    if(cnt&1){
        it = next(it);
        if(it==lst.end()) flag = true;
    } 
    
    vector<pair<int,int>> prevAns;
    
    while(!flag && next(it)!=lst.end() && ((next(it)->size())%2!=0)){
        pair<int,int> fb = it->back();
        pair<int,int> bf = next(it)->front();
        it->pop_back();
        next(it)->pop_front();
        swap(bf.second,fb.second);
        it->push_back(fb);
        while(!next(it)->empty()){
            it->push_back(next(it)->front());
            next(it)->pop_front();
        }
        it->push_back(bf);
        pair<int,int> ans = {fb.first,bf.first};
        prevAns.push_back(ans);

        lst.erase(next(it));

        if(next(it)!=lst.end() && ((next(it)->size())%2!=0)) it = next(it);
    }

    vector<pair<int,int>> afterAns;

    for(auto &deq : lst){
        pair<int,int> fi = deq.front();
        deq.pop_front();

        while(deq.size()>2){
            pair<int,int> t1 = deq.front();
            deq.pop_front();
            pair<int,int> t2 = deq.front();
            deq.pop_front();

            pair<int,int> pans = {fi.first,t2.first};
            pair<int,int> aans = {t1.first,t2.first};

            prevAns.push_back(pans);
            afterAns.push_back(aans);
        }

        if(deq.size()==2){
            pair<int,int> t1 = deq.front();
            deq.pop_front();
            pair<int,int> t2 = deq.front();
            deq.pop_front();

            pair<int,int> aans = {fi.first,t1.first};
            afterAns.push_back(aans);
            aans = {fi.first,t2.first};
            afterAns.push_back(aans);
        }
        else{
            pair<int,int> t = deq.front();
            deq.pop_front();

            pair<int,int> aans = {fi.first,t.first};

            afterAns.push_back(aans);
        }
    }

    if(prevAns.size()>N/2){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";
    cout<<prevAns.size()<<'\n';
    for(auto i : prevAns){
        if(i.first>i.second) swap(i.first,i.second);
        cout<<i.first<<' '<<i.second<<'\n';
    } 

    cout<<afterAns.size()<<'\n';
    for(auto i : afterAns){
        if(i.first>i.second) swap(i.first,i.second);
        cout<<i.first<<' ' <<i.second<<'\n';
    } 

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}