#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<ll, 2> pll;

void solve() {
    int N;
    cin>>N;

    vector<pair<int,int>> score(N);

    for (int i=0;i<N;i++) {
        int A,B;
        char ch;
        cin>>A>>ch>>B;
        score[i] = {A,B};
    }

    int A = -1,B = -1;

    bool flag = false;
    for (int i=0;i<N;i++) {
        // A,B
        int sum = score[i].first + score[i].second;

        if (sum%4==1 || sum%4==2)
            swap(score[i].first,score[i].second);
        if (score[i].first == 11 && score[i].second == 11) {
            cout<<"error "<<i+1<<'\n';
            return;
        }
        if (score[i].first>=11 || score[i].second>=11) {
            if (flag) {
                if (score[i].first==A && score[i].second==B) {
                    continue;
                }
                else {
                    cout<<"error "<<i+1<<'\n';
                    return;
                }
            }
            flag = true;
        }

        if (A<=score[i].first && B<=score[i].second) {
            A = score[i].first, B = score[i].second;
        }
        else {
            cout<<"error "<<i+1<<'\n';
            return;
        }
    }

    cout<<"ok";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1; // cin >> t;
    while (t--) solve();
}