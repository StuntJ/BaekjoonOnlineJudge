#include <iostream>
#include <vector>

using namespace std;

void printStar(int x,int y,int N,vector<vector<char>> &stars)
{
    if(N==1)
    {
        stars[x][y] = '*';
        return;
    }
    int increase = N/3;

    for(int i=x;i<x+N;i+=increase)
    {
        for(int j=y;j<y+N;j+=increase)
        {
            if(i==x+increase&&j==y+increase) continue;
            printStar(i,j,N/3,stars);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    vector<vector<char>> stars(N,vector<char>(N,' '));

    printStar(0,0,N,stars);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<stars[i][j];
        cout<<'\n';
    }
}
