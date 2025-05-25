#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;

ll pow(ll n, ll p)
{
	if (p == 0) return 1;
	ll temp = pow(n, p / 2);
	ll ret = temp * temp;
	if (p & 1) return n * ret;
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_map<string, ll> mp;
	mp.insert({ "black",0 });
	mp.insert({ "brown",1 });
	mp.insert({ "red",2 });
	mp.insert({ "orange",3 });
	mp.insert({ "yellow",4 });
	mp.insert({ "green",5 });
	mp.insert({ "blue",6 });
	mp.insert({ "violet",7 });
	mp.insert({ "grey",8 });
	mp.insert({ "white",9 });

	string str1, str2, str3;
	cin >> str1 >> str2 >> str3;
	ll p = (mp[str1] * 10 + mp[str2]) * pow(10LL, mp[str3]);
	cout << p;
}