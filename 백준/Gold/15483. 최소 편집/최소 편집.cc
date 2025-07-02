#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str1, str2;
	cin >> str1 >> str2;
	str1.insert(str1.begin(), '@');
	str2.insert(str2.begin(), '@');
	int s1 = str1.size();
	int s2 = str2.size();

	vector<vector<int>> dp(s1, vector<int>(s2));
	for (int i = 0; i < s1; i++) dp[i][0] = i;
	for (int i = 0; i < s2; i++) dp[0][i] = i;

	for (int i = 1; i < s1; i++) {
		for (int j = 1; j < s2; j++) {
			if (str1[i] == str2[j]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
		}
	}
	cout << dp[s1 - 1][s2 - 1];
}