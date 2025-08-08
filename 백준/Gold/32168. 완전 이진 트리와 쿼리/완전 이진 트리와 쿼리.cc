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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N,Q;
    cin>>N>>Q;

    auto find = [&](auto &find, ll root, ll L, ll R, ll ob)->bool{
        if(L>R) return false;
        if(ob<L) return false;
        if(L<=ob&&ob<=R) return true;
        bool ret = false;
        ret |= find(find,root,L*2,min(N,R*2+1),ob);
        return ret;
    };

    auto add = [&](ll v)->ll{
        if(v>N) return 0LL;
        ll sum = v;
        ll l = (v<<1), r = (v<<1)+1;

        while(l<=N){
            r = min(r,N);
            sum += (r-l+1)*(r+l)/2;
            l = l<<1;
            r = (r<<1)+1;
        }
        return sum;
    };

    ll root = 1;
    while(Q--){
        int q;
        cin>>q;
        if(q==1){
            ll r;
            cin>>r;
            root = r;
        }
        else{
            ll node;
            cin>>node;

            if(find(find,node,node,node,root)){
                ll prev;
                ll sum = node;
                if(node==root){
                    cout<<add(1)<<'\n';
                    continue;   
                }
                else if(find(find,node*2,node*2,min(N,node*2),root)){
                    sum += add(node*2+1);
                }
                else{
                    sum += add(node*2);
                }
                while(node){
                    prev = node;
                    node /= 2;
                    if(node==0) break;
                    sum += node;
                    if(node*2==prev){
                        sum += add(node*2+1);
                    }
                    else{
                        sum += add(node*2);
                    }
                }
                cout<<sum<<'\n';
            }
            else cout<<add(node)<<'\n';
        }
        
    }
}