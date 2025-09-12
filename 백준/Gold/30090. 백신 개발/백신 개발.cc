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

const int LIM = 10;
int adj[LIM][LIM];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<string> v(N);
    for(auto &i : v) cin>>i;
    int totsize = 0;
    for(auto i : v) totsize+=i.size();

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            
        }
    }

    vector<int> seq(N);
    for(int i=0;i<N;i++) seq[i] = i;
    int tot = 10000;
    do{
        int sum = 0;
        bool flag = true;
        string str = v[seq[0]];
        for(int i=1;i<N;i++){
            int sz = min(str.size(),v[seq[i]].size());
            int st = 0;
            for(int k=1;k<=sz;k++){
                if(str.substr(str.size()-k,k)==v[seq[i]].substr(0,k)) st = max(st,k);
            }
            str += v[seq[i]].substr(st);
        }
        tot = min((int)str.size(),tot);
        //cout<<str<<'\n';
    }while(next_permutation(seq.begin(),seq.end()));

    cout<<tot;
}