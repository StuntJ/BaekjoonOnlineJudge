#include <bits/stdc++.h>
using namespace  std;
 
typedef long long ll;
typedef array<ll, 2> pll;
#define all(x) (x).begin(), (x).end()
 
 
void solve() {
    string str;
    cin>>str;
 
    bool triple = false;
    bool doub = false;
    int tripN = -1;
    int doubN = -1;
    for (int i=0;i<(int)str.size()-2;i++) {
        if (str.substr(i,3)=="SSS") {
            triple = true;
            tripN = i;
            break;
        }
    }
 
    for (int i=0;i<(int)str.size()-1;i++) {
        if (str.substr(i,2)=="SS") {
            doub = true;
            doubN = i;
            break;
        }
    }
 
    if (triple) {
        string strOr;
        for (auto i : str) strOr.push_back(i+32);
        str = strOr;
        string strA = str.substr(0,tripN);
        string strB = strA;
        strA += "Bs";
        strB += "sB";
        strA += str.substr(tripN+3);
        strB += str.substr(tripN+3);
        cout<<str<<'\n';
        cout<<strA<<'\n';
        cout<<strB<<'\n';
    }
    else if (doub) {
        string strOr;
        for (auto i : str) strOr.push_back(i+32);
        str = strOr;
        string strA = str.substr(0,doubN);
        strA += "B";
        strA += str.substr(doubN+2);
        cout<<str<<'\n';
        cout<<strA<<'\n';
    }
    else {
        string strOr;
        for (auto i : str) strOr.push_back(i+32);
        cout<<strOr<<'\n';
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1; // cin >> t;
    while (t--) {
        solve();
    }
}