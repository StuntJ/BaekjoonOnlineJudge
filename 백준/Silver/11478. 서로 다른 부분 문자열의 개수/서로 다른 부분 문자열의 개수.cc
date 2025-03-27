#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	set<string> st;

	for(int i=0;i<str.size();i++)
	{
		for (int j = 1; j <= str.size(); j++)
		{
			if (i + j > str.size()) break;
			st.insert(str.substr(i, j));
		}
	}
	cout << st.size();
}