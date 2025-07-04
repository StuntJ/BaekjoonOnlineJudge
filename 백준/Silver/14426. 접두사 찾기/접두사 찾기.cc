#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_set<string> st;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= str.size(); j++) {
			st.insert(str.substr(0, j));
		}
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		if (st.find(str) != st.end()) cnt++;
	}
	cout << cnt << '\n';
}