#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<ll, 2> pll;

void toX(int &currentX, int towardX) {
    string str;
    if (currentX<=towardX) str = "right\n";
    else str = "left\n";
    for (int i=0;i<abs(currentX-towardX);i++) cout<<str;
    currentX = towardX;
}

void toY(int &currentY, int towardY) {
    string str;
    if (currentY<=towardY) str = "up\n";
    else str = "down\n";
    for (int i=0;i<abs(currentY-towardY);i++) cout<<str;
    currentY = towardY;
}

void solve() {
    int N;
    cin>>N;

    int curX,curY,Dx,Dy;
    cin>>curX>>curY>>Dx>>Dy;

    vector<pair<int,int>> vp(N);
    for (auto &i : vp) cin>>i.first>>i.second;

    // toY(curY,-10);
    // cout<<curY;

    //logic

    toX(curX,31);
    toY(curY,curY-1);
    toX(curX,63);
    toY(curY,curY+1);
    toX(curX,31);
    toY(curY,Dy);

    for (int j=0;j<Dy;j++) {
        toX(curX,Dx);
        toX(curX,31);
        toY(curY,-1);
        for (int i=30;i>=Dx;i--) {
            toX(curX,i);
            toY(curY,j);
            toY(curY,-1);
        }
        toX(curX,31);
        toY(curY,Dy);
    }

    for (int j=30;j>Dy;j--) {
        toX(curX,Dx);
        toX(curX,31);
        toY(curY,31);
        for (int i=30;i>=Dx;i--) {
            toX(curX,i);
            toY(curY,j);
            toY(curY,31);
        }
        toX(curX,31);
        toY(curY,Dy);
    }
    toX(curX,Dx);
    toY(curY,31);
    toX(curX,-1);
    toY(curY,Dy);

    for (int j=0;j<Dy;j++) {
        toX(curX,Dx);
        toX(curX,-1);
        toY(curY,-1);
        for (int i=0;i<Dx;i++) {
            toX(curX,i);
            toY(curY,j);
            toY(curY,-1);
        }
        toX(curX,-1);
        toY(curY,Dy);
    }

    for (int j=30;j>Dy;j--) {
        toX(curX,Dx);
        toX(curX,-1);
        toY(curY,31);
        for (int i=0;i<Dx;i++) {
            toX(curX,i);
            toY(curY,j);
            toY(curY,31);
        }
        toX(curX,-1);
        toY(curY,Dy);
    }
    toX(curX,Dx);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1; // cin >> t;
    while (t--) solve();
}