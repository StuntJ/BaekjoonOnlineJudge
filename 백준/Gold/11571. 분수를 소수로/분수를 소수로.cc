#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int a, b;
		cin >> a >> b;
		int z = a / b;
		int md = a % b;
		md *= 10;
		map<int, int> mp;
		vector<int> v;
		int idx = 0;
		while (mp.find(md) == mp.end()) {
			v.push_back(md / b);
			mp.insert(make_pair(md, idx));
			idx++;
			md %= b;
			md *= 10;
		}
		int f = mp[md];
		cout << z << '.';
		for (int i = 0; i < v.size(); i++) {
			if (i == f) cout << '(';
			cout << v[i];
		}
		cout << ")\n";
	}
}