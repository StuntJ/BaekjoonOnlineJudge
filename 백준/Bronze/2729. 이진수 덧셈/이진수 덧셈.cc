#include <bits/stdc++.h>

using namespace std;

void plus_bit(string& a, string& b)
{
	string ans;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	bool flag = 0;
	int n = max(a.size(), b.size());
	for (int i = 0; i < n; i++)
	{
		int here = 0;
		if (i < a.size() && a[i] == '1') here++;
		if (i < b.size() && b[i] == '1') here++;
		if (flag)
		{
			here += flag;
			flag = false;
		}
		if (here & 1) ans.push_back('1');
		else ans.push_back('0');
		if (here >= 2) flag = true;
		else flag = false;
	}
	if (flag) ans.push_back('1');
	while (ans.size()>1 && ans[ans.size() - 1] == '0')
		ans.pop_back();
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string A, B;
		cin >> A >> B;
		plus_bit(A,B);
	}
}