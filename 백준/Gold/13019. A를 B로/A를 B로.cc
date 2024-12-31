#include <bits/stdc++.h>

using namespace std;

int alphaA[26];
int alphaB[26];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string A, B;
	cin >> A >> B;

	for (auto i : A) alphaA[i - 'A']++;
	for (auto i : B) alphaB[i - 'A']++;

	for (int i = 0; i < 26; i++)
		if (alphaA[i] != alphaB[i])
		{
			cout << -1;
			return 0;
		}

	int idx = B.size() - 1;
	int ans = 0;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		if (A[i] == B[idx]) idx--;
		else ans++;
	}
	cout << ans;
}