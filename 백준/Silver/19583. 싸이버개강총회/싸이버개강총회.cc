#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<vector<pi>> vvpi;
typedef vector<vector<vector<pi>>> vvvpi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<long double> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

struct stringv{
    string str;
    bool operator <= (const stringv& rhs) const{
        int ah = stoi(str.substr(0,2));
        int bh = stoi(rhs.str.substr(0,2));
        int am = stoi(str.substr(3,2));
        int bm = stoi(rhs.str.substr(3,2));
        if(ah==bh){
            return am<=bm;
        }
        else return ah<=bh;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stringv begin,st,nd;
    cin>>begin.str>>st.str>>nd.str;

    stringv chat;
    string nick;
    set<string> start,end;
    while(cin>>chat.str>>nick){
        if(chat<=begin){
            start.insert(nick);
        }
        if(st<=chat&&chat<=nd){
            end.insert(nick);
        }
    }

    int cnt = 0;
    for(auto nick : start){
        if(end.find(nick)!=end.end()) cnt++;
    }
    cout<<cnt;
}