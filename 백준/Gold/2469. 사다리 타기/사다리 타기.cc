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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int H;
    cin >> H;
    vi seq(N);
    for (int i = 0; i < N; i++)
    {
        char x;
        cin >> x;
        seq[i] = x - 'A';
    }
    vector<string> v(H);
    int k;
    for (int i = 0; i < H; i++)
    {
        cin >> v[i];
        if (v[i][0] == '?') k = i;
    }

    vi up(N);
    for (int i = 0; i < N; i++)
    {
        int idx = i;
        for (int j = 0; j < k; j++)
        {
            if (idx == 0)
            {
                if (v[j][idx] == '-') idx++;
            }
            else if (idx == N - 1)
            {
                if (v[j][idx - 1] == '-') idx--;
            }
            else
            {
                if (v[j][idx - 1] == '-') idx--;
                else if (v[j][idx] == '-') idx++;
            }
        }
        up[idx] = i;
    }

   
    vi down(N);
    for (int i = 0; i < N; i++)
    {
        int idx = i;
        for (int j = H-1; j > k; j--)
        {
            if (idx == 0)
            {
                if (v[j][idx] == '-') idx++;
            }
            else if (idx == N - 1)
            {
                if (v[j][idx - 1] == '-') idx--;
            }
            else
            {
                if (v[j][idx - 1] == '-') idx--;
                else if (v[j][idx] == '-') idx++;
            }
        }
        down[idx] = seq[i];
    }

    vc res(N - 1);
    bool flag = false;
    for (int i = 0; i < N; i++)
    {
        if (up[i] == down[i])
        {
            res[i] = '*';
            if (i > 0) res[i - 1] = '*';
            continue;
        }
        else if (i != N-1 && up[i] == down[i + 1] && down[i] == up[i + 1])
        {
            res[i] = '-';
            if(i!=N-2) res[i + 1] = '*';
            i++;
            continue;
        }
        else
        {
            flag = true;
            break;
        }
    }

    if (flag) for (int i = 0; i < N - 1; i++) cout << 'x';
    else for (auto i : res) cout << i;
}