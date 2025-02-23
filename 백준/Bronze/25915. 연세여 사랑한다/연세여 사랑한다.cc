#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str = "ILOVEYONSEI";

	char ch;
	cin >> ch;

	int dist = 0;
	for(int i=0;i<str.size();i++)
	{
		dist += abs(ch-str[i]);
		ch = str[i];
	}
	cout << dist << '\n';
}