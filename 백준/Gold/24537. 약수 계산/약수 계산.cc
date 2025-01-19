#include <bits/stdc++.h>
#define MAX_N 1000001
using namespace std;

int gcdCnt[MAX_N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		gcdCnt[x] ++;
	}

	for (int i = 1; i < MAX_N; i++)
		for (int j = i * 2; j < MAX_N; j+=i)	
			gcdCnt[i] += gcdCnt[j];
	
	for (int i = 1; i < MAX_N; i++)
	{
		if (gcdCnt[i] == 0) gcdCnt[i] = -1;
		for (int j = i * 2; j < MAX_N; j += i)
		{
			if (gcdCnt[i] == gcdCnt[j]) gcdCnt[i] = -1;
		}
	}
	int Q;
	cin >> Q;
	while (Q--)
	{
		int x;
		cin >> x;

		cout << gcdCnt[x] << '\n';
	}
}