#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int xm=1001,xM = 0, ym = 1001, yM = 0;
    int x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    set<pair<int,int>> vertex;
    vertex.insert({x1,y1});
    vertex.insert({x2,y2});
    vertex.insert({x3,y3});
    xm = min(x1,min(x2,x3));
    xM = max(x1,max(x2,x3));
    ym = min(y1,min(y2,y3));
    yM = max(y1,max(y2,y3));

    double S = fabs((double)x1*(y2-y3)+(double)x2*(y3-y1)+(double)x3*(y1-y2))/2.0;

    auto getx = [&](int x1, int y1, int x2, int y2, int y)->double{
        if(y2-y1==0) return -1;
        return (double)(x2-x1)/(double)(y2-y1)*(double)(y-y2)+x2;
    };

    int N;
    cin>>N;
    int ans = 0;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        pair<int,int> p = {a,b};
        if(vertex.find(p)!=vertex.end())
        {
            ans++;
            continue;
        }
        if(b<ym || yM<b) continue;
        if(a<xm||xM<a) continue;
        vector<double> xset;
        xset.push_back(getx(x1,y1,x2,y2,b));
        xset.push_back(getx(x2,y2,x3,y3,b));
        xset.push_back(getx(x1,y1,x3,y3,b));
        
        for(auto iter = xset.begin();iter!=xset.end();iter++){
            if(*iter<xm||xM<*iter) {
                xset.erase(iter);
                break;
            }
        }

        sort(xset.begin(),xset.end());
        /* cout<<"x : ";
        for(auto i : xset) cout<<i<<' ';
        cout<<'\n';  */
        if(xset[0]<=a && a<=xset[1])
            ans++;
    }
    cout<<fixed;
    cout.precision(1);
    cout<<S<<'\n';
    cout<<ans;
}