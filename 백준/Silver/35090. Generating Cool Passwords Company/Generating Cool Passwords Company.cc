#include <bits/stdc++.h>
using namespace  std;
 
typedef long long ll;
typedef array<ll, 2> pll;
#define all(x) (x).begin(), (x).end()
 
 
void solve() {
    int N;
    cin>>N;
 
    int cnt = 0;
    for (char i = 'a';i<='z';i++) {
        for (char j='A';j<='Z';j++) {
            for (char k='0';k<='9';k++) {
                for (char l='!';l<='/';l++) {
                    string str;
                    str.push_back(i);
                    str.push_back(i);
                    str.push_back(j);
                    str.push_back(j);
                    str.push_back(k);
                    str.push_back(k);
                    str.push_back(l);
                    str.push_back(l);
                    cnt++;
                    cout<<str<<'\n';
                    if (cnt>=N) break;
                }
                if (cnt>=N) break;
            }
            if (cnt>=N) break;
        }
        if (cnt>=N) break;
    }
 
}
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1; // cin >> t;
    while (t--) {
        solve();
    }
}