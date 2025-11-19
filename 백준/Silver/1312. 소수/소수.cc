#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A,B;
    cin>>A>>B;

    int N;
    cin>>N;

    int r = A%B;
    int q = A/B;
    for(int i=0;i<N;i++){
        r*=10;
        q = r/B;
        r = r%B;
    }
    cout<<q;
}