#include <bits/stdc++.h>

using namespace std;

int fibo[50];

void initFibo()
{
	fibo[0] = fibo[1] = 1;
	for (int i = 2; i < 50; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	initFibo();

	int N;
	cin >> N;

	cout << fibo[N];
}