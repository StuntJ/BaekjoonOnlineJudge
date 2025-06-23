#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,Q;
    cin>>N>>Q;

    vector<int> v(N);
    for(auto &i : v) cin>>i;
    vector<int> rv = v;
    for(auto &i : rv) i = -i;
    reverse(rv.begin(),rv.end());

    auto solve = [&](vector<int> &p)->vector<int>{
        vector<int> arr;
        vector<int> ret(N);
        for(int i=0;i<N;i++){
            int t = p[i];
            auto it = lower_bound(arr.begin(),arr.end(),t);
            int idx = it-arr.begin();
            if(it==arr.end())
                arr.push_back(t);
            else arr[idx] = t;
            ret[i] = idx+1;
        }

        return ret;
    };

    vector<int> a = solve(v);
    vector<int> b = solve(rv);
    reverse(b.begin(),b.end());
    /* for(auto &i : a) cout<<i<<' ';
    cout<<'\n';
    for(auto &i : b) cout<<i<<' ';
    cout<<'\n'; */

    while(Q--){
        int x;
        cin>>x;
        x--;
        cout<<a[x]+b[x]-1<<'\n';
    }
}