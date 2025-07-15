#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<vector<pi>> vvpi;
typedef vector<vector<vector<pi>>> vvvpi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<long double> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;

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

vector2 findIntersection(vector2 a, vector2 b, vector2 c, vector2 d){
    double det = (b-a).cross(d-c);
    return a+(b-a)*((c-a).cross(d-c)/det);
}

int segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2 &p){ 
    //ab 와 cd가 한 점에서 만나면 p에 교점을 저장하고 1 return
    //ab 와 cd가 겹쳐있으면 -1 return
    //ab 와 cd가 만나지 않는다면 0 return
    double ab = ccw(a,b,c)*ccw(a,b,d);
    double cd = ccw(c,d,a)*ccw(c,d,b);
    if(ab==0&&cd==0){
        if(b<a) swap(a,b);
        if(d<c) swap(c,d);
        if(fabs(ccw(a,b,c))<DBL_EPSILON&&fabs(ccw(b,c,d))<DBL_EPSILON){
            if(a==d) { p=a; return 1; } //한쪽 끝에서 만남
            else if(b==c) { p=b; return 1;} //한쪽 끝에서 만남
            else return -1; //선분이 겹쳐있음
        }
        else if(!(b<c||d<a)){
            p = findIntersection(a,b,c,d);
            return 1; //한 점에서 만남
        }
        else return 0; //평행
    }
}

//p에서 ab에 내린 수선의 발 return
vector2 perpendicularFoot(vector2 p, vector2 a, vector2 b){
    return a+(p-a).project(b-a);
}

//p에서 ab에 내린 수선의 발의 길이 (norm)
double pointToLine(vector2 p, vector2 a, vector2 b){
    return (p-perpendicularFoot(p,a,b)).norm();
}

//다각형의 넓이 O(n)
double area(const vector<vector2> &p){
    double ret = 0;
    for(int i=0;i<p.size();i++){
        int j = (i+1)%p.size();
        ret += p[i].x*p[j].y-p[j].x*p[i].y;
    }
    return fabs(ret)/2.0;
}

//주어진 점이 단순 다각형 내부에 포함되어 있는지 판별 O(n)
bool isInside(vector2 q, const vector<vector2> &p){
    int crosses = 0;
    for(int i=0;i<p.size();i++){
        int j = (i+1)%p.size();
        if((p[i].y>q.y)!=(p[j].y>q.y)){ 
            double atX = (p[j].x-p[i].x)*(q.y-p[i].y)/(p[j].y-p[i].y)+p[i].x;
            if(q.x<atX)
                ++crosses;
        }
    }
    return crosses%2>0;
}

//주어진 점이 볼록 다각형 내부에 포함되어 있는지 판별 O(nlogn)
typedef vector<vector2> polygon;
//주의!!!!!!!!! polygon의 좌표는 반시계 방향으로 주어졌다고 가정한다.
bool isInside(polygon &p, vector2 &point){
    int n = p.size();
    if(ccw(p[0],p[1],point)<0) return false;
    if(ccw(p[0],p[n-1],point)>0) return false;
    int left = 1, right = n-1;
    int ans = 1;
    while(left<=right){
        int mid = (left+right)/2;
        if(ccw(p[0],p[mid],point)>0){
            ans = max(ans,mid);
            left = mid+1;
        }
        else right = mid-1;
    }
    return ccw(p[ans],point,p[ans+1])<=0;
}

//볼록껍질 알고리즘 Graham Scan O(nlogn)
//point에 좌표를 집어넣으면 볼록껍질로 만들어준다.
//반드시 typedef vector<vector2> polygon; 을 선언하고 사용할 것
polygon grahamScan(vector<vector2> &point){
    sort(point.begin(),point.end());
    vector2 minE = point[0];
    sort(point.begin()+1,point.end(),[&](vector2 a, vector2 b){
        double res = ccw(minE,a,b);
        if(fabs(res)<DBL_EPSILON) return (a-minE).norm()<(b-minE).norm();
        return res>0;
    });
    stack<vector2> st;
    st.push(point[0]);
    st.push(point[1]);
    int next = 2;
    while(next<point.size()){
        vector2 a,b;
        while(st.size()>=2){
            b = st.top();
            st.pop();
            a = st.top();
            if(ccw(a,b,point[next])>0){
                st.push(b);
                break;
            }
        }
        st.push(point[next++]);
    }
    polygon poly;
    //시계방향으로 점들이 들어감
    while(!st.empty()){
        poly.emplace_back(st.top());
        st.pop();
    }
    return poly;
}

//볼록껍질의 가장 긴 지름 구하기 (Rotating calipers) O(n) 
double diameter(const polygon &p){
    int n = p.size();
    int left = min_element(p.begin(),p.end())-p.begin();
    int right = max_element(p.begin(),p.end())-p.begin();
    double ret = (p[right]-p[left]).norm();
    vector2 calipersA(0,1);
    vector<vector2> toNext(n);
    for(int i=0;i<n;i++) toNext[i] = (p[(i+1)%n]-p[i]).normalize();
    int a = left, b = right;
    while(a!=right||b!=left){
        double cosThetaA = calipersA.dot(toNext[a]);
        double cosThetaB = -calipersA.dot(toNext[b]);
        if(cosThetaA>cosThetaB){
            calipersA = toNext[a];
            a = (a+1)%n;
        }
        else{
            calipersA = toNext[b]*(-1);
            b = (b+1)%n;
        }
        ret = max(ret,(p[a]-p[b]).norm());
    }
    
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout<<fixed;
    cout.precision(2);

    int t = 0;
    while(true){
        t++;
        int N;
        cin>>N;
        if(N==0) return 0;

        vector<vector2> v(N);
        for(auto &i : v) cin>>i.x>>i.y;
        polygon p = grahamScan(v);

        ll sz = p.size();
        double ans = 1e10;
        for(int i=0;i<sz;i++){
            double diameter = 0.0;
            int idx = i+2;
            for(int j=0;j<sz-2;j++){
                diameter = max(diameter,pointToLine(p[idx%sz],p[i],p[(i+1)%sz]));
                idx++;
            }
            
            ans = min(ans,diameter);
        }
        
        ans*=100.0;
        if(ans-(ll)ans> 1e-12){
            ans+=1;
            ans = (ll)ans;
        }
        ans/=100.0;
        cout<<"Case "<<t<<": "<<ans<<'\n';
        //cout<<p.size()<<'\n';
    }
}