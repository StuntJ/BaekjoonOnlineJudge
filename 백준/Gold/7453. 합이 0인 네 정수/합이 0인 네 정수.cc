#include <bits/stdc++.h>

using namespace std;

//다음은 크기가 최대 4000인 A, B, C, D 배열이 있을 때 A[a] + B[b] + C[c] + D[d]가 0인 순서쌍의 개수를 묻는 문제이다.
//일반적인 방법으로 완전 탐색 (Brute Force)를 진행한다고 하면 시간복잡도는 O(4000^4) 정도 걸린다.
//하지만 A + B 의 모든 경우를 fi배열에 저장하고, C + D 의 모든 경우를 se배열에 저장하면 시간복잡도는 O(4000^2) 이다.
//-1 * (A + B) 가 C + D 값이 될 것이다. C + D 배열을 정렬하고 이분탐색을 실시하여 값을 찾는다.
//이 문제에서는 A, B, C, D 의 순서쌍의 개수를 구하라고 하였으므로, 중복된 값도 그대로 배열에 저장을 해야한다.
//이분탐색을 할 때도 중복된 값을 고려하여 upper_bound - lower_bound 를 답에 더해주면 되겠다.

typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<ll> A, B, C, D;
	A = B = C = D = vector<ll>(N);
	for (int i = 0; i < N; i++)
		cin >> A[i] >> B[i] >> C[i] >> D[i];

	vector<ll> fi, se;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			fi.emplace_back(A[i] + B[j]);
			se.emplace_back(C[i] + D[j]);
		}
	}

	sort(se.begin(), se.end());

	ll ans = 0;
	for (int i = 0; i < fi.size(); i++)
	{
		ll need = -fi[i];
		ll num = upper_bound(se.begin(), se.end(), need) - lower_bound(se.begin(), se.end(), need);
		ans += num;
	}
	cout << ans;
}