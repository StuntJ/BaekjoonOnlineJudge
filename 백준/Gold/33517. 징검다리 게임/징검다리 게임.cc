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

struct info{
    bool mine = false;
    int att = 0;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    vi v(N);
    for(auto &i : v) cin>>i;
    int M;
    cin>>M;
    string str;
    cin>>str;
    if(str.find('J')==str.npos){
        cout<<"NO";
        return 0;
    }
    vector<info> vinfo;
    int here = 0;
    info st;
    for(int i=0;i<str.size();i++){
        if(str[i]=='J'){
            here = (i+1)%str.size();
            break;
        }
        else{
            if(str[i]=='D') st.mine = true;
            else st.att++;
        }
    }
    
    info temp;
    int rep = M;
    while(rep--){
        if(str[here]=='J'){
            vinfo.push_back(temp);
            temp.mine = false;
            temp.att = 0;
        }
        else{
            if(str[here]=='D'){
                temp.mine = true;
            }
            if(str[here]=='A'){
                temp.att++;
            }
        }
        
        here = (here+1)%str.size();
    }
    
    int idx = 0;
    for(int i=1;i<N;i++){
        if(i==1){
            if(v[i]==-1){
                if(st.mine) continue;
                else{
                    cout<<"NO";
                    return 0;
                }
            }
            else if(v[i]>0){
                if(v[i]<=st.att) continue;
                else{
                    cout<<"NO";
                    return 0;
                }
            }
            else continue;
        }
        if(v[i]==-1){
            if(vinfo[idx].mine){
                idx = (idx+1)%vinfo.size();
                continue;
            } 
            else{
                cout<<"NO";
                return 0;
            }
        }
        else if(v[i]>0){
            if(vinfo[idx].att>=v[i]){
                idx = (idx+1)%vinfo.size();
                continue;
            }
            else{
                cout<<"NO";
                return 0;
            }
        }
        else{
            idx = (idx+1)%vinfo.size();
            continue;
        }
    }
    cout<<"YES";
}