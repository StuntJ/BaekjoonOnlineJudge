#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	getline(cin, str);

	string oneHole = "AabDdegOoPpQqR@"; //1개 구멍
	string twoHole = "B"; //2개구멍

	int cnt = 0;
	for (auto ch : str)
	{
		for (auto i : oneHole)
			if (ch == i) cnt++;

		for (auto i : twoHole)
			if (ch == i) cnt+=2;
	}
	cout << cnt;
}