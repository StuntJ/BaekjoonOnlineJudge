#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1e15;

void solve(){
    ll N,B;
    cin>>N>>B;

    vector<array<ll,2>> v(N);
    for(auto &i : v) for(auto &j : i) cin>>j;
    for(auto &i : v) swap(i[1],i[0]);

    sort(v.begin(),v.end(), [&](array<ll,2> &a, array<ll,2> &b){
        return a[0]<b[0];
    });

    vector<ll> ans(N,INF);

    function<void(vector<array<ll,2>>&, int, bool)> calc = [&](vector<array<ll,2>> &arr, int here, bool rev){
        int left = here;
        int right = here+1;
        
        while(right<N && left>=0){
            while(right<N && abs(arr[right][0]-arr[left][0])>=arr[right][1]){ //right exist and can destroy right
                right++;
            }
            if(right==N) break;
            if(abs(arr[right][0]-arr[left][0])>=arr[left][1]){ //if left is destroyable
                ans[(!rev ? left : N-left-1)] = min(ans[(!rev ? left : N-left-1)],abs(arr[right][0]-arr[left][0])-arr[left][1]);
                left--;
            }
            else{
                while(left>=0){
                    ans[left] = 0;
                    left--;
                }
                break;
            }
        }
    };

    int start = upper_bound(v.begin(),v.end(),B, [&](const ll &b, const array<ll,2> &a){
        return b<a[0];
    }) - v.begin() - 1;

    if(start==N-1||start==-1){
        cout<<-1;
        return;
    }

    calc(v,start,false);

    reverse(v.begin(),v.end());

    calc(v,N-start-2,true);

    ll tot = INF;
    for(int i=0;i<N;i++){
        tot = min(tot, ans[i]);
    }

    cout<<(tot==INF ? -1 : tot)<<'\n';
    //for(int i=0;i<N;i++) cout<<ans[i]<<' ';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin>>t;

    while(t--){
        solve();
    }
}