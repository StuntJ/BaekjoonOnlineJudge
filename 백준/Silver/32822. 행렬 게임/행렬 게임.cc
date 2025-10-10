#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> hoon(N + 1, vector<int>(N + 1));
    vector<vector<int>> chan(N + 1, vector<int>(N + 1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> hoon[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> chan[i][j];
        }
    }

    vector<int> p(N + 1);
    for (int j = 1; j <= N; j++) {
        int diff = -1;
        int ans = -1;
        for (int i = 1; i <= N; i++) {
            if (diff < abs(hoon[i][j] - chan[i][j])) {
                diff = abs(hoon[i][j] - chan[i][j]);
                ans = i;
            }
        }
        p[j] = ans;
    }

    int ans = 0;
    vector<int> b(M);
    for (int i = 0; i < M; i++) {
        cin >> b[i];
        int beta = b[i];
        int alpha = p[beta];
        ans += abs(hoon[alpha][beta] - chan[alpha][beta]);
    }
    cout << ans;

}