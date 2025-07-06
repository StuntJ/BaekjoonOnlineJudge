#include <bits/stdc++.h>

using namespace std;

int md[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int mdsp[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
typedef long long ll;

ll convert(int y, int m, int d, int hh, int mm, int ss){
    y%=100;
    ll ret = (y-1)*365 + (y-1)/4;
    if(y%4==0){
        ret+=mdsp[m-1];
    }
    else ret+=md[m-1];

    ret += d;
    ret *= 86400;

    ret += (hh*3600+mm*60+ss);

    return ret;
}

int main(){
    for(int i=1;i<=12;i++){
        md[i] += md[i-1];
        mdsp[i] += mdsp[i-1];
    }
    int N;
    cin>>N;

    if(N==0){
        cout<<0;
        return 0;
    }

    vector<pair<ll,int>> v; //t,lv
    for(int i=0;i<N;i++){
        int y,m,d,hh,mm,ss;
        int lv;
        scanf("%d/%d/%d %d:%d:%d %d",&y,&m,&d,&hh,&mm,&ss,&lv);
        //cout<<y<<' '<<m<<' '<<d<<' '<<hh<<' '<<mm<<' '<<ss<<' '<<lv<<'\n';
        ll t = convert(y,m,d,hh,mm,ss);
        //cout<<t<<'\n';
        v.push_back({t,lv});
    }
    v.insert(v.begin(),{0.0,0});
    vector<long double> p(N+1);
    long double Xtop = 0.0;
    for(int i=1;i<=N;i++){
        p[i] = max(pow(0.5L,((v[N].first-v[i].first)/86400.0L)/365.0L),pow(0.9L,N-i));  
        Xtop += p[i]*v[i].second;
    }
    long double Xbot = accumulate(p.begin()+1,p.end(),0.0);
    cout<<round(Xtop/Xbot);
}