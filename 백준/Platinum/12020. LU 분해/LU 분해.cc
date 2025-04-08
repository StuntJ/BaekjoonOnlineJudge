#include <iostream>
#include <cmath>
#include <cfloat>
#include <vector>
using namespace std;

typedef vector<vector<double>> Matrix;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	Matrix mat(N);
	Matrix I(N);

	double bp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> bp;
			mat[i].push_back(bp);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j) I[i].push_back(1.0);
			else I[i].push_back(0.0);
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (abs(mat[i][i]) < DBL_EPSILON)
		{
			for (int k = i; k < N; k++)
			{
				if (abs(mat[k][i]) > DBL_EPSILON)
				{
					vector<double> temp;
					temp = mat[i];
					mat[i] = mat[k];
					mat[k] = temp;
					temp = I[i];
					I[i] = I[k];
					I[k] = temp;
					break;
				}
			}
		}		

		double cval = mat[i][i];
		for (int k = i; k < N; k++)
		{
			if (k == i) continue;
			double divval = mat[k][i] / cval;
			I[k][i] = divval;
			for (int j = i; j < N; j++)
			{

				mat[k][j] -= (mat[i][j] * divval);
			}
		}
	}
	bool flag = true;

	for (int i = 0; i < N-1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (abs(I[i][j]) > DBL_EPSILON)
				flag = false;
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (abs(mat[i][i]) < DBL_EPSILON)
			flag = false;
	}

	if (flag)
	{
		cout << fixed;
		cout.precision(3);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << I[i][j] << " ";
			}
			cout << '\n';
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << mat[i][j] << " ";
			}
			cout << '\n';
		}
	}
	else
		cout << -1;
}