#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, L;
	cin >> N >> L;
	vector<vector<int>> grid(N, vector<int>(N));
	for (auto& i : grid)
		for (auto& j : i)
			cin >> j;
	
	vector<vector<int>> v = grid;
	for (int j = 0; j < N; j++){
		vector<int> z;
		for (int i = 0; i < N; i++){
			z.push_back(v[i][j]);
		}
		v.push_back(z);
	}
	
	int ans = 0;
	for (auto vec : v) {
		bool flag = true;
		vector<bool> chk(N);
		//cout << vec.size();
		//for (auto i : vec)
		//	cout << i << ' ';
		//cout << '\n';
		for (int i = 1; i < N; i++) {
			if (vec[i - 1] == vec[i] - 1) { 
				if (i - L < 0) {
					flag = false;
					break;
				}
				int num = vec[i - 1];
				bool f = false;
				for (int j = i - L; j < i; j++)
				{
					if (vec[j] != num){
						f = true;
						break;
					}
					if (chk[j]){
						f = true;
						break;
					}
				}
				if (f) {
					flag = false;
					break;
				}
				else {
					for (int j = i - L; j < i; j++)
						chk[j] = true;
				}
			}
			else if (vec[i - 1] == vec[i] + 1) {
				if (i + L - 1 >= N) {
					flag = false;
					break;
				}
				int num = vec[i];
				bool f = false;
				for (int j = i; j <= i + L - 1; j++)
				{
					if (vec[j] != num) {
						f = true;
						break;
					}
					if (chk[j]) {
						f = true;
						break;
					}
				}
				if (f) {
					flag = false;
					break;
				}
				else {
					for (int j = i; j <= i + L-1; j++)
						chk[j] = true;
				}
			}
			else {
				if (vec[i - 1] != vec[i]) {
					flag = false;
				}
			}

		}
		//cout << flag << '\n';
		ans += flag;
	}

	cout << ans << '\n';
}