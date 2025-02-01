#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--)
	{
		ll Hn, Hs;
		cin >> Hn >> Hs;

		ll Na, Nh, Sa, Sh;
		cin >> Na >> Nh >> Sa >> Sh;

		bool Nwin;
		bool Draw = false;

		if (Na >= Hs) Nwin = true;
		else if (Hn + Nh <= Sa) Nwin = false;
		else if (Nh >= Sa && Sh >= Na) Draw = true;
		else if (Nh<Sa && Sh>Na) Nwin = false;
		else if (Nh > Sa && Sh < Na) Nwin = true;
		else
		{
			ll n = Hs / Na;
			if (Hs % Na) n++;
			ll s = Hn / Sa;
			if (Hn % Sa) s++;

			if (Nh < Sa && Sh == Na)
			{
				if (n <= s) Draw = true;
				else Nwin = false;
			}
			if (Nh == Sa && Sh < Na)
			{
				if (n <= s) Nwin = true;
				else Draw = true;
			}
			else
			{
				if (n <= s) Nwin = true;
				else Nwin = false;
			}
		}
		
		if (Draw) cout << "DRAW\n";
		else if (Nwin) cout << "NARUTO\n";
		else cout << "SASUKE\n";
	}
}