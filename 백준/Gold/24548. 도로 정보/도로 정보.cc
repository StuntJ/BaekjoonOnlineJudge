#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	string str;
	cin >> str;

	vector<int> T(N + 1), G(N + 1), F(N + 1), P(N + 1);
	str.insert(str.begin(), '\0');
	for (int i = 1; i <= N; i++) {
		switch (str[i]) {
		case 'T':
			T[i]++;
			break;
		case 'G':
			G[i]++;
			break;
		case 'F':
			F[i]++;
			break;
		case 'P':
			P[i]++;
			break;
		}
		T[i] += T[i - 1];
		G[i] += G[i - 1];
		F[i] += F[i - 1];
		P[i] += P[i - 1];
	}
	
	map<int, int> state;
	int ans = 0;
	for (int i = 0; i <= N; i++) {
		int st = T[i] % 3 + G[i] % 3 * 3 + F[i] % 3 * 9 + P[i] % 3 * 27;
		if(state.find(st)!=state.end())
			ans += state[st];
		state[st]++;
	}
	cout << ans;
}