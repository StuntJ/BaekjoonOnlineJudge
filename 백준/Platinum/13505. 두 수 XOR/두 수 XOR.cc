#include <bits/stdc++.h>

using namespace std;

struct Trie{
    Trie* next[2] = {nullptr};
    bool finish = false;
}T;

void insert(string &s){
    Trie* t = &T;
    for(char a : s){
        if(t->next[a-'0']==nullptr) t->next[a-'0'] = new Trie;
        t = t->next[a-'0'];
    }
    t->finish = true;
}

int search(string &s){
    int ret = 0;
    int k = 0;
    Trie* t = &T;
    for(char a : s){
        int nx = !(a-'0');
        if(t->next[nx]==nullptr){
            k++;
            t = t->next[!nx]; 
        }
        else{
            t = t->next[nx];
            ret += (1<<(30-k));
            k++;
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<int> v(N);
    for(auto &i : v) cin>>i;

    //cout<<(1<<30)<<'\n';
    vector<string> vstr(N);
    for(int i=0;i<N;i++){
        string str = "";
        for(int k=30;k>=0;k--){
            if((v[i]>=(1<<k))){
                v[i]-=(1<<k);
                str += "1";
            }
            else str +="0";
        }
        //cout<<str<<'\n';
        insert(str);
        vstr[i] = str;
    }

    int mx = 0;
    for(auto st : vstr){
        mx = max(mx,search(st));
    }
    cout<<mx;
}
