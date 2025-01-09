#include <bits/stdc++.h>

using namespace std;

const double PI = 2.0 * acos(0.0);

struct vector2
{
    double x,y;
    explicit vector2(double x_ = 0, double y_ = 0) : x(x_),y(y_) {}

    bool operator == (const vector2 &rhs) const
    {
        return fabs(x-rhs.x)<DBL_EPSILON && fabs(y-rhs.y)<DBL_EPSILON;
    }

    bool operator < (const vector2 &rhs) const
    {
        return fabs(x-rhs.x)>=DBL_EPSILON ? x<rhs.x : y<rhs.y;
    }

    vector2 operator + (const vector2 &rhs) const
    {
        return vector2(x+rhs.x,y+rhs.y);
    }

    vector2 operator - (const vector2 &rhs) const
    {
        return vector2(x-rhs.x,y-rhs.y);
    }

    vector2 operator * (double rhs) const
    {
        return vector2(x*rhs,y*rhs);
    }

    double norm() const { return hypot(x,y); }
    vector2 normalize() const { return vector2(x/norm(),y/norm()); }
    double polar() const { return fmod(atan2(y,x)+PI*2,PI*2); }

    double dot(const vector2 &rhs) const
    {
        return x*rhs.x + y*rhs.y;
    }

    double cross(const vector2 &rhs) const
    {
        return x*rhs.y - rhs.x*y;
    }

    vector2 project(const vector2 &rhs) const
    {
        vector2 r = rhs.normalize();
        return r*r.dot(*this);
    }
};

double ccw(vector2 a, vector2 b)
{
    return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b)
{
    return ccw(a-p,b-p);
}

typedef vector<vector2> polygon;

polygon grahamScan(vector<vector2> &point)
{
    polygon res;
    if(point.size()==1)
    {
        res.emplace_back(point[0]);
        return res;
    }

    sort(point.begin(),point.end());
    vector2 minE = point[0];
    sort(point.begin()+1,point.end(),[&](vector2 a, vector2 b)
        {
            double res = ccw(minE,a,b);
            if(fabs(res)<DBL_EPSILON) return (a-minE).norm() < (b-minE).norm();
                return res>0;
        }); //no problem until here

    stack<vector2> st;
    st.push(point[0]);
    st.push(point[1]);
    int next = 2;
    vector2 a,b;
    while(next<point.size())
    {
        while(st.size()>=2)
        {
            b = st.top();
            st.pop();
            a = st.top();
            if(ccw(a,b,point[next])>0)
            {
                st.push(b);
                break;
            }
        }
        st.push(point[next++]);
    }

    while(!st.empty())
    {
        res.emplace_back(st.top());
        st.pop();
    }
    return res;
}

bool isInside(vector2 q,polygon &p)
{
    int crosses = 0;
    for(int i=0;i<p.size();i++)
    {
        int j = (i+1)%p.size();
        if((p[i].y)>q.y != (p[j].y>q.y))
        {
            double atX = (p[j].x - p[i].x) * (q.y - p[i].y)/(p[j].y-p[i].y) + p[i].x;
            if(q.x<atX)
                ++crosses;
        }
    }
    return crosses%2>0;
}

bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d)
{
    double ab = ccw(a,b,c) * ccw(a,b,d);
    double cd = ccw(c,d,a) * ccw(c,d,b);

    if(fabs(ab)<DBL_EPSILON && fabs(cd)<DBL_EPSILON)
    {
        if(b<a) swap(a,b);
        if(d<c) swap(c,d);
        return !(b<c||d<a);
    }
    return ab<=0 && cd <=0;
}

bool polygonIntersects(polygon &p, polygon &q)
{
    int n = p.size(), m = q.size();
    if(isInside(p[0],q)||isInside(q[0],p)) return true;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(segmentIntersects(p[i],p[(i+1)%n],q[j],q[(j+1)%m]))
                return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin>>T;

    for(int t=0;t<T;t++)
    {
        int N,M;
        cin>>N>>M;


        vector<vector2> blackPoint(N);
        vector<vector2> whitePoint(M);

        for(int i=0;i<N;i++)
            cin>>blackPoint[i].x>>blackPoint[i].y;

        for(int i=0;i<M;i++)
            cin>>whitePoint[i].x>>whitePoint[i].y;

        if(N==1 && M==1)
        {
            cout<<"YES"<<'\n';
            continue;
        }

        polygon black = grahamScan(blackPoint);
        polygon white = grahamScan(whitePoint);

        if(N==1 && M==2)
        {
            if(fabs(ccw(white[0],black[0],white[1]))<DBL_EPSILON) cout<<"NO"<<'\n';
            else cout<<"YES"<<'\n';
        }
        else if(N==2 && M==1)
        {
            if(fabs(ccw(black[0],white[0],black[1]))<DBL_EPSILON) cout<<"NO"<<'\n';
            else cout<<"YES"<<'\n';
        }
        else
        {
            if(polygonIntersects(black,white)) cout<<"NO"<<'\n';
            else cout<<"YES"<<'\n';
        }
    }
}
