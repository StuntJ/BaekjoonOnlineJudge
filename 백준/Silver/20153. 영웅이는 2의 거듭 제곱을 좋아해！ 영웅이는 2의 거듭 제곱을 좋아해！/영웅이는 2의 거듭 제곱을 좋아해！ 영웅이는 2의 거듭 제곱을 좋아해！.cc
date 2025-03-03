#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int x = 0;
	vector<int> num(N);
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
		x ^= num[i];
	}

	int maximum = x;
	for (int i = 0; i < N; i++)
	{
		maximum = max(maximum, num[i] ^ x);
	}

	string str = to_string(maximum);

	cout << str << str;
}