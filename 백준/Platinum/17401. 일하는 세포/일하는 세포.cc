#include <bits/stdc++.h>
#define DIV 1000000007

using namespace std;
typedef long long ll;
typedef vector<vector<ll>> Matrix;

Matrix E;

Matrix matrixProduct(Matrix &A, Matrix &B)
{
	int N = A.size();
	int M = A[0].size();
	int K = B[0].size();

	Matrix C = Matrix(N, vector<ll>(K));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			for (int k = 0; k < M; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
				C[i][j] %= DIV;
			}
		}
	}

	return C;
}

Matrix matrixPow(Matrix A, ll p)
{
	if (p == 0) return E;
	Matrix temp = matrixPow(A, p / 2);
	temp = matrixProduct(temp, temp);
	if (p & 1) return matrixProduct(temp, A);
	return temp;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	ll D;
	cin >> T >> N >> D;

	Matrix tset = Matrix(N, vector<ll>(N));

	for (int i = 0; i < N; i++) tset[i][i] = 1;
	E = tset;

	vector<Matrix> mtxSet;

	int t = T;
	while (t--)
	{
		int M;
		cin >> M;

		Matrix P = Matrix(N, vector<ll>(N));

		for (int i = 0; i < M; i++)
		{
			int a, b;
			ll c;
			cin >> a >> b >> c;
			a--, b--;

			P[a][b] = c;
		}

		tset = matrixProduct(tset, P);
		mtxSet.emplace_back(P);
	}

	Matrix ans = matrixPow(tset, D / T);
	for (int i = 0; i < D % T; i++)
	{
		ans = matrixProduct(ans,mtxSet[i]);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
}