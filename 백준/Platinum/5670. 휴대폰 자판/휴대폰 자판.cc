#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Trie{
    unordered_map<int,Trie*> c;
    //Trie* c[26] = {nullptr};
    bool here = false;
    ll nodeCnt = 0;
};

void insert(string s,Trie* t){
    for(char a : s){
        if(t->c[a-'a']==nullptr){
            t->c[a-'a'] = new Trie();
            t->nodeCnt++;
        }
        t = t->c[a-'a'];
    }
    t -> here = true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    while(cin>>N){
        Trie root;
        for(int i=0;i<N;i++){
            string str;
            cin>>str;
            insert(str,&root);
        }

        ll sum = 0LL;
        auto cal = [&](auto &cal, Trie *p, ll ret)->void{
            if(p->here==true){
                sum += ret;
            }
            if(p->nodeCnt==0) return;
            else if(p->nodeCnt==1){
                if(p->here){
                    for(auto next : p->c){
                        cal(cal,next.second,ret+1);
                    }
                }
                else{
                    for(auto next : p->c)
                        cal(cal,next.second,ret);
                }
            }
            else{
                for(auto next : p->c)
                    cal(cal,next.second,ret+1);
            }
        };
        for(auto next : root.c){
            cal(cal,next.second,1LL);
        }
        cout<<fixed;
        cout.precision(2);

        cout<<(double)sum/N<<'\n';
    }


}