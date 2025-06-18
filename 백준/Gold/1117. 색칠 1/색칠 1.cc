#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll W, H, f, c, x1, y1, x2, y2;
	cin >> W >> H >> f >> c >> x1 >> y1 >> x2 >> y2;
	if (f > W / 2) f = W - f;

	ll s1 = 0, s2 = 0;
	if (x1 < f) s1 = (min(x2,f) - x1) * (y2 - y1);
	if (x2 > f) s2 = (x2 - max(x1,f)) * (y2 - y1);
	ll ans = (s1 * 2 + s2) * (c + 1);

	cout << W*H - ans;
}