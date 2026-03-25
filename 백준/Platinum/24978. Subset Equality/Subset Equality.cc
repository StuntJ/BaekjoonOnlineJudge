#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    string S,T;
    cin>>S>>T;

    vector<pair<char,char>> ban;
    vector<char> banSol;

    int snum[26], tnum[26];
    memset(snum,0,sizeof(snum));
    memset(tnum,0,sizeof(tnum));

    for(auto i : S) snum[i-'a']++;
    for(auto i : T) tnum[i-'a']++;

    for(int i=0;i<26;i++){
        if(snum[i]!=tnum[i]) banSol.push_back(i+'a');
    }

    function<bool(char, char)> check = [&](char a, char b){
        int sidx = 0;
        int tidx = 0;

        bool flag = false;
        while(true){
            while(S[sidx] != a && S[sidx] != b && sidx<S.size()){
                sidx++;
            }
            while(T[tidx] != a && T[tidx] != b && tidx<T.size()){
                tidx++;
            }

            if(sidx==S.size() && tidx==T.size()){
                flag = true;
                break;
            }
            else if(sidx==S.size() && tidx<T.size()) break;
            else if(sidx<S.size() && tidx==T.size()) break;
            else{
                if(S[sidx]==T[tidx]){
                    sidx++;
                    tidx++;
                    continue;
                }
                else{
                    break;
                }
            }
        }

        return flag;
    };

    for(char ch1 = 'a'; ch1<='r'; ch1++){
        for(char ch2 = ch1+1; ch2<='r';ch2++){
            if(!check(ch1,ch2)){
                ban.push_back({ch1,ch2});
            }
        }
    }

    int Q;
    cin>>Q;
    while(Q--){
        string R;
        cin>>R;

        bool num[26];
        memset(num,0,sizeof(num));
        
        for(auto i : R){
            num[i-'a'] = true;
        }


        bool Neg = false;
        for(auto i : ban){
            if(num[i.first-'a']&&num[i.second-'a']){
                Neg = true;
                break;
            }
        }

        for(auto i : banSol){
            if(num[i-'a']){
                Neg = true;
                break;
            }
        }
        cout<<(Neg ? "N" : "Y");
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