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
	int sum = 0;
	for (auto i : str)
	{
		sum += i - '0';
	}
	cout << sum;
}