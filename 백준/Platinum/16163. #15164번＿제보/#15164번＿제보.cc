#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<vector<pi>> vvpi;
typedef vector<vector<vector<pi>>> vvvpi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<long double> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

//매내처 알고리즘은 팰린드롬의 대칭성을 이용하는 알고리즘이다.
// 함수의 리턴값은 i로 부터 팰린드롬의 최대 반지름을 저장하는 배열이다.
// 짝수 팰린드롬을 구하기 위해, "ABCDEGDSE" -> "@A@B@C@D@E@G@D@S@E@" 꼴로 만들어 계산한다. 이때 계산되는 값이 팰린드롬의 길이가 된다.
//https://ialy1595.github.io/post/manacher/를 참조한다.

vector<int> manacher(string str)
{
	int p = -1, r = -1;
	int len = str.size();
	vector<int> res(len);

	for (int i = 0; i < len; i++)
	{
		if (i > r) //끝 범위보다 크면 대칭성을 사용할 수 없다.
		{
			p = r = i;
			while (r < len && 0 <= 2 * p - r && str[r] == str[2 * p - r]) r++;
			r--;
			res[i] = r - p;

		}
		else
		{
			int j = 2 * p - i;
			if (res[j] < r - i)
				res[i] = res[j];
			else if (res[j] > r - i)
				res[i] = r - i;
			else
			{
				p = i;
				while (r < len && 0 <= 2 * p - r && str[r] == str[2 * p - r]) r++;
				r--;
				res[i] = r - p;

			}
		}
	}
	return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	string str;
	cin >> str;

	ll ans = str.size();

	string newStr = "@";
	for (auto i : str)
	{
		newStr += i;
		newStr += "@";
	}

	vi v = manacher(newStr);

	
	for (auto i : v)
	{
		//cout << i << ' ';
		ans += i / 2;
	}
	//cout << '\n';
	cout << ans;
}