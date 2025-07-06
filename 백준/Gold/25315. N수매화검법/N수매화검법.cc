#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const double PI = 2.0*acos(0.0);
struct vector2{
    double x,y;
    explicit vector2(double x_=0, double y_=0) : x(x_),y(y_){}
    bool operator == (const vector2 &rhs) const{
        return fabs(x-rhs.x)<DBL_EPSILON && fabs(y-rhs.y)<DBL_EPSILON;
    }

    bool operator < (const vector2 &rhs) const{
        return fabs(x-rhs.x)>=DBL_EPSILON ? x<rhs.x : y<rhs.y;
    }

    vector2 operator + (const vector2 &rhs) const{
        return vector2(x+rhs.x,y+rhs.y);
    }

    vector2 operator - (const vector2 &rhs) const{
        return vector2(x-rhs.x, y-rhs.y);
    }

    vector2 operator * (double rhs) const{
        return vector2(x*rhs,y*rhs);
    }

    double norm() const { return hypot(x,y); }
    vector2 normalize() const { return vector2(x/norm(), y/norm()); }
    double polar() const { return fmod(atan2(y,x)+2*PI,2*PI); }
    double dot(const vector2 &rhs) const{
        return x*rhs.x+y*rhs.y;
    }

    double cross(const vector2 &rhs) const{
        return x*rhs.y-rhs.x*y;
    }

    vector2 project(const vector2 &rhs) const{
        vector2 r = rhs.normalize();
        return r*r.dot(*this);
    }
};

double ccw(vector2 a, vector2 b){
    return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b){
    return ccw(a-p,b-p);
}

bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2 &x){
    double det = (b-a).cross(d-c);
    if(fabs(det)<DBL_EPSILON) return false;
    x = a+(b-a)*((c-a).cross(d-c)/det); //x는 교점의 좌표
    return true;
}

bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d){
    double ab = ccw(a,b,c) * ccw(a,b,d);
    double cd = ccw(c,d,a) * ccw(c,d,b);
    if(ab==0&&cd==0){ //평행할 때
        if(b<a) swap(a,b);
        if(d<c) swap(c,d);
        return !(b<c||d<a);
    }
    return ab<=0 && cd<=0;
}

struct cutData{
    vector2 s;
    vector2 e;
    ll w;
    bool operator < (const cutData &rhs) const{
        return w<rhs.w;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    vector<cutData> v(N);
    for(auto &i : v) cin>>i.s.x>>i.s.y>>i.e.x>>i.e.y>>i.w;
    sort(v.begin(),v.end());

    vector<vector<int>> adj(N);
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(segmentIntersects(v[i].s,v[i].e,v[j].s,v[j].e)){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    ll ans = 0;
    for(int i=0;i<N;i++){
        ll cnt = 0;
        for(auto j : adj[i]){
            if(j<=i) continue;
            cnt++;
        }
        ans += (cnt+1)*v[i].w;
    }
    cout<<ans;
}