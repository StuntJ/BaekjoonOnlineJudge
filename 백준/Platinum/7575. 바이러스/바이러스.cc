#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

template <typename T = string>
vector<int> getPartialMatch(const T &N)
{
    int m = N.size();
    vector<int> pi(m,0);

    int begin = 1, matched = 0;

    while(begin+matched < m){
        if(N[begin + matched] == N[matched]){
            ++matched;
            pi[begin+matched-1] = matched;
        }
        else{
            if(matched == 0)
                ++begin;
            else{
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }

    return pi;
}

template <typename T = string>
bool kmpSearch(const T &H, const T &N){
    int n = H.size(), m = N.size();
    vector<int> pi = getPartialMatch<T>(N);
    int begin = 0, matched = 0;
    while(begin <= n-m){
        if(matched < m && H[begin + matched] == N[matched]){
            ++matched;
            if(matched == m) return true;
        }
        else{
            if(matched == 0)
                ++begin;
            else{
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,K;
    cin>>N>>K;

    vector<vector<int>> v(N);
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        for(int j=0;j<x;j++){
            int k;
            cin>>k;
            v[i].emplace_back(k);
        }
    }

    for(int i=0;i+K<=v[0].size();i++){
        vector<int> x = vector<int>(v[0].begin()+i,v[0].begin()+i+K);
        vector<int> rx = x;
        reverse(rx.begin(),rx.end());
        bool res = true;
        for(int j=1;j<N;j++){
            bool t = (kmpSearch<vector<int>>(v[j],x)|kmpSearch<vector<int>>(v[j],rx));
            res &= t;
        }
        if(res){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}