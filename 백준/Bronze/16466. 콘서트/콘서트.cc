#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int main()
{
	int N;
	cin >> N;

	const int lim = 1000001;
	unordered_set<int> st;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		st.insert(x);
	}

	for(int i=1;i<=lim;i++)
		if (st.find(i) == st.end())
		{
			cout << i;
			return 0;
		}
}