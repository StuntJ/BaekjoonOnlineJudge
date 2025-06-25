#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

struct p{
    int a; //top
    int b; //bottom
    bool operator < (const p &rhs) const{
        return (double)a/b < (double)rhs.a/rhs.b;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,K;
    cin>>N>>K;

    //set<p> st;
    //st.insert({0,1});
    //st.insert({1,1});
    vector<p> v;
    v.push_back({0,1});
    for(int i=2;i<=N;i++){
        for(int j=1;j<=i/2;j++){
            int a = j;
            int b = i;
            int g = gcd(a,b);
            if(g!=1) continue;
            a/=g;
            b/=g;
            v.push_back({a,b});
            //st.insert({a,b});
        }
    }

    //vector<p> v = vector<p>(st.begin(),st.end());
    //sort(v.begin(),v.end());
    //for(auto &i : v) cout<<i.a<<' '<<i.b<<'\n';
    if(K-1>=v.size()){
        int t = v.size()*2-1-(K-1)-1;
        nth_element(v.begin(),v.begin()+t,v.end());
        cout<<v[t].b-v[t].a<<' '<<v[t].b;
    }
    else
    {
        nth_element(v.begin(),v.begin()+K-1,v.end());
        cout<<v[K-1].a<<' '<<v[K-1].b;
    }
}