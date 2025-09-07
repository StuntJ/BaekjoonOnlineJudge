#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    vector<int> v(N);
    for(auto &i : v) cin>>i;
    vector<int> v2;
    for(auto i : v) v2.emplace_back(i);
    for(auto i : v) v2.emplace_back(i);
    int sum = accumulate(v.begin(),v.end(),0);
    int target = sum/2;

    int ans = 0;
    int p1 = 0;
    int temp = 0;
    for(int p2 = 0; p2<v2.size(); p2++){
        temp += v2[p2];
        while(temp>target){
            temp-=v2[p1];
            p1++;
        }
        ans = max(ans,temp);
    }

    cout<<ans<<'\n';
}