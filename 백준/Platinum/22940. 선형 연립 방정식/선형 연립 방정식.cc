#include <iostream>
#include <vector>
#include <cfloat>
#include <cmath>
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
	int bp;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N + 1; j++)
		{
			cin >> bp;
			mat[i].push_back(bp);
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
					break;
				} 
			}
		}
		double val = mat[i][i];
		for (int j = i; j < N + 1; j++)
			mat[i][j] /= val;

		double cval = mat[i][i];
		for (int k = 0; k < N; k++)
		{
			if (k == i) continue;
			double divval = mat[k][i] / cval;
			for (int j = i; j < N + 1; j++)
			{
				mat[k][j] -= (mat[i][j] * divval);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << mat[i][N] << " ";
	}
}