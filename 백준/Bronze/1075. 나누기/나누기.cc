#include <bits/stdc++.h>

using namespace std;

int main()
{

	int N, F;
	cin >> N >> F;

	string str = to_string(N);
	str[str.size() - 2] = str[str.size() - 1] = '0';
	int p = stoi(str);

	int idx = 0;
	for (int i = p; i <= p + 99; i++)
	{
		if (i % F == 0)
		{
			printf("%02d", idx);
			return 0;
		}
		idx++;
	}
}