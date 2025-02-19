#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

Matrix matrixProduct(const Matrix &A,const Matrix &B,int N,int M,int K)
{
    int bp = 0;
    Matrix sol(N,vector<int>(K,0));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<K;j++)
        {
            for(int k=0;k<M;k++)
            {
                bp+=A[i][k]*B[k][j];
            }
            sol[i][j] = bp;
            bp = 0;
        }
    }
    return sol;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,K;
    int bp;

    cin>>N>>M;
    Matrix A(N);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>bp;
            A[i].emplace_back(bp);
        }

    }


    cin>>M>>K;

    Matrix B(M);

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<K;j++)
        {
            cin>>bp;
            B[i].emplace_back(bp);
        }

    }


    Matrix C = matrixProduct(A,B,N,M,K);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<K;j++)
            cout<<C[i][j]<<' ';
        cout<<'\n';
    }
}
