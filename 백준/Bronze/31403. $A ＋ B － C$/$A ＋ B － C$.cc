#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string A, B, C;
	cin >> A >> B >> C;
	cout << stoi(A) + stoi(B) - stoi(C) << '\n';

	string D = A + B;
	cout << stoi(D) - stoi(C);
}