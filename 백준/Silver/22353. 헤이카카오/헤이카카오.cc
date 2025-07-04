#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cout << fixed;
	cout.precision(6);
	int a, d, k;
	cin >> a >> d >> k;

	double nd = d;
	double st = 1;
	double ans = 0;
	int idx = 1;
	while (nd < 100) {
		ans += st * ((double)nd / 100) * a * idx;
		//cout << st * ((double)nd / 100) * a * idx << '\n';
		idx++;
		st *= (1 - (double)nd / 100);
		nd += nd * (double)k / 100;
	}
	ans += st * (min(100.0,nd) / 100) * a * idx;
	cout << ans;
}