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

int fpow(int n, int p){
    int ret = 1;
    for(int i=0;i<p;i++){
        ret*=n;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,T,G;
    cin>>N>>T>>G;

    const int LIM = 100000;
    vb visited(LIM);

    queue<pi> q;
    visited[N] = true;
    q.push({N,0});
    int ans = -1;
    while(!q.empty()){
        int here = q.front().first;
        int dist = q.front().second;
        //cout<<here<<' '<<dist<<'\n';
        q.pop();

        if(dist>T) continue;
        if(here==G){
            ans = dist;
            break;
        }

        if(here+1<LIM){
            if(!visited[here+1]){
                visited[here+1] = true;
                q.push({here+1,dist+1});
            }
        }

        if(here!=0 && here*2<LIM){
            int mul = -1;
            for(int i=0;i<6;i++){
                int p = fpow(10,i);
                if(here*2/p==0){
                    mul = p/10;
                    break;
                }
            }
            int next = here*2-mul;
            if(!visited[next]){
                visited[next] = true;
                q.push({next,dist+1});
            }
            
        }
    }

    if(ans==-1) cout<<"ANG";
    else cout<<ans;
}