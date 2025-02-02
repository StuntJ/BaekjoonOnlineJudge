#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int H, W, N;
        cin >> H >> W >> N;
        int b = (N - 1) / H + 1;
        int a = N % H;
        if (a == 0) a = H;
        if(b<10)cout << a <<0<< b << '\n';
        else cout << a << b << '\n';
    }
}