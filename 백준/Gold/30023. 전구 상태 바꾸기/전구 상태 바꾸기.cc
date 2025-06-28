#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  
    int N;
    string a;
    cin >> N >> a;
    vector<int> tmpA(N);
    vector<int> tmpB(N);
    vector<int> tmpC(N);
    for (int i = 0; i < N; ++i) {
        if (a[i] == 'R') tmpA[i] = tmpB[i] = tmpC[i] = 0;
        else if (a[i] == 'G') tmpA[i] = tmpB[i] = tmpC[i] = 1;
        else tmpA[i] = tmpB[i] = tmpC[i] = 2;
    }
    int ansA = 0, ansB = 0, ansC = 0;
    for (int i = 0; i < N - 2; ++i) {
        if (tmpA[i] == 1) {
            tmpA[i + 1] = (tmpA[i + 1] + 2) % 3;
            tmpA[i + 2] = (tmpA[i + 2] + 2) % 3;
            ansA += 2;
        }
        else if (tmpA[i] == 2) {
            tmpA[i + 1] = (tmpA[i + 1] + 1) % 3;
            tmpA[i + 2] = (tmpA[i + 2] + 1) % 3;
            ansA += 1;
        }

        if (tmpB[i] == 2) {
            tmpB[i + 1] = (tmpB[i + 1] + 2) % 3;
            tmpB[i + 2] = (tmpB[i + 2] + 2) % 3;
            ansB += 2;
        }
        else if (tmpB[i] == 0) {
            tmpB[i + 1] = (tmpB[i + 1] + 1) % 3;
            tmpB[i + 2] = (tmpB[i + 2] + 1) % 3;
            ansB += 1;
        }

        if (tmpC[i] == 0) {
            tmpC[i + 1] = (tmpC[i + 1] + 2) % 3;
            tmpC[i + 2] = (tmpC[i + 2] + 2) % 3;
            ansC += 2;
        }
        else if (tmpC[i] == 1) {
            tmpC[i + 1] = (tmpC[i + 1] + 1) % 3;
            tmpC[i + 2] = (tmpC[i + 2] + 1) % 3;
            ansC += 1;
        }
    }
    const int INF = 1e9;
    if (tmpA[N - 1] != 0 || tmpA[N - 2] != 0) ansA = INF;
    if (tmpB[N - 1] != 1 || tmpB[N - 2] != 1) ansB = INF;
    if (tmpC[N - 1] != 2 || tmpC[N - 2] != 2) ansC = INF;
    int ans = min({ ansA,ansB,ansC });
    if (ans == INF) ans = -1;
    cout << ans;
}