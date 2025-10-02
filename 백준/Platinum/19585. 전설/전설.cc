#include <bits/stdc++.h>

using namespace std;

unordered_set<string> u_set;

struct Trie{
    Trie* c[26] = {nullptr};
    bool finish = false;
}T;

void insert(string s){
    Trie* t = &T;
    for(char a : s){
        if(t->c[a-'a'] == nullptr){
            t->c[a-'a'] = new Trie;
        }
        t = t->c[a-'a'];
    }
    t->finish = true;
}

bool search(string s){
    Trie* t = &T;
    int idx = 0;
    for(int i=0;i<s.size();i++){
        if(t->finish){
            if(u_set.find(s.substr(i))!=u_set.end()) return true;
        }
        if(t->c[s[i]-'a']==nullptr) return false;
        t = t->c[s[i]-'a'];
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int C,N;
    cin>>C>>N;

    for(int i=0;i<C;i++){
        string col;
        cin>>col;
        
        insert(col);    
    }
    for(int i=0;i<N;i++){
        string name;
        cin>>name;
        u_set.insert(name);
    }

    int Q;
    cin>>Q;
    while(Q--){
        string col;
        cin>>col;
        if(search(col)) cout<<"Yes\n";
        else cout<<"No\n";
    }


}