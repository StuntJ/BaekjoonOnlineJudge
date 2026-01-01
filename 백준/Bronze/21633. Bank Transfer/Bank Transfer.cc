#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
	cin>>k;
	
	double ans = 25 + 1.0/100.0*k;
	ans = min(ans,2000.0);
	ans = max(ans,100.0);
	cout<<ans;
}