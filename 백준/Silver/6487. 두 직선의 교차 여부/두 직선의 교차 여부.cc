#include <iostream>
#include <cfloat>
#include <cmath>

using namespace std;

const double PI = 2.0 * acos(0.0);

struct vector2
{
    double x,y;

    explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

    bool operator == (const vector2 &rhs) const
    {
        return x==rhs.x && y==rhs.y;
    }

    bool operator < (const vector2 &rhs) const
    {
        return x!=rhs.x ? x<rhs.x : y<rhs.y;
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

    vector2 normallize() const
    {
        return vector2(x/norm(),y/norm());
    }

    double polar() const { return fmod(atan2(y,x)+PI*2,PI*2); }

    double dot(const vector2 &rhs) const
    {
        return x*rhs.x + y*rhs.y;
    }

    double cross(const vector2 &rhs) const
    {
        return x*rhs.y - y*rhs.x;
    }

    vector2 project(const vector2 &rhs) const
    {
        vector2 r = rhs.normallize();
        return r*r.dot(*this);
    }
};

double ccw(vector2 x, vector2 y)
{
    return x.cross(y);
}

double ccw(vector2 p1, vector2 p2, vector2 p3)
{
    return ccw(p1 - p2, p3 - p2);
}

void lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d)
{
    double det = (b-a).cross(d-c);
    if(fabs(det)<DBL_EPSILON)
    {
        if(ccw(a,b,c)<DBL_EPSILON&&ccw(b,c,d)<DBL_EPSILON) cout<<"LINE\n";
        else cout<<"NONE\n";
    }
    else
    {
        vector2 ans = a + (b-a)*((c-a).cross(d-c)/det);
        cout<<fixed;
        cout.precision(2);
        cout<<"POINT "<<ans.x<<' '<<ans.y<<'\n';
    }
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
        vector2 a,b,c,d;
        cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
        lineIntersection(a,b,c,d);
    }
}
