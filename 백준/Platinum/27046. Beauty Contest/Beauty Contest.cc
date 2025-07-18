#include <bits/stdc++.h>

using namespace std;

const double PI = 2.0 * acos(0.0);

struct vector2
{
    double x,y;

    explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

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
        return vector2(x+rhs.x, y+rhs.y);
    }

    vector2 operator - (const vector2 &rhs) const
    {
        return vector2(x-rhs.x, y-rhs.y);
    }

    vector2 operator * (double rhs) const
    {
        return vector2(x*rhs, y*rhs);
    }

    double norm() const { return hypot(x,y); }
    vector2 normalize() const { return vector2(x/norm(),y/norm()); }

    double polar() const { return fmod(atan2(y,x) + PI*2, PI*2); }

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
    return ccw(a-p, b-p);
}

typedef vector<vector2> polygon;

polygon grahamScan(vector<vector2> &point)
{
    sort(point.begin(),point.end());
    vector2 minE = point[0];
    sort(point.begin()+1,point.end(),[&](vector2 a, vector2 b)
         {
             double res = ccw(minE,a,b);
             if(fabs(res)<DBL_EPSILON) return (a-minE).norm()<(b-minE).norm();
             return res>0;
         });

    stack<vector2> st;
    st.push(point[0]);
    st.push(point[1]);
    int next = 2;
    while(next<point.size())
    {
        vector2 a,b;
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

    polygon poly;
    while(!st.empty())
    {
        poly.emplace_back(st.top());
        st.pop();
    }
    return poly;
}

double diameter(polygon &p)
{
    int n = p.size();

    int left = min_element(p.begin(),p.end()) - p.begin();
    int right = max_element(p.begin(),p.end()) - p.begin();

    double ret = (p[right]-p[left]).norm();
    vector<vector2> toNext(n);

    for(int i=0;i<n;i++)
        toNext[i] = (p[(i+1)%n]-p[i]).normalize();


    vector2 calipersA = vector2(0,1);

    int a = left, b = right;
    while(a!=right||b!=left)
    {
        double cosThetaA = calipersA.dot(toNext[a]);
        double cosThetaB = -calipersA.dot(toNext[b]);
        if(cosThetaA>cosThetaB)
        {
            calipersA = toNext[a];
            a = (a+1)%n;
        }
        else
        {
            calipersA = toNext[b]*(-1);
            b = (b+1)%n;
        }
        ret = max(ret,(p[a]-p[b]).norm());
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed;
    cout.precision(0);

    int N;
    cin>>N;

    vector<vector2> orginpoint(N);
    vector<vector2> point;

    for(int i=0;i<N;i++)
        cin>>orginpoint[i].x>>orginpoint[i].y;

    queue<int> sameidx;
    sort(orginpoint.begin(),orginpoint.end());
    for(int i=0;i<N-1;i++)
        if(orginpoint[i] == orginpoint[i+1]) sameidx.push(i);

    for(int i=0;i<N;i++)
    {
        if(!sameidx.empty()&&i==sameidx.front())
        {
            sameidx.pop();
            continue;
        }
        point.emplace_back(orginpoint[i]);
    }
    N = point.size();

    bool flag = true;
    for(int i=2;i<N;i++)
        if(fabs(ccw(point[i-2],point[i-1],point[i]))>=DBL_EPSILON)
        {
            flag = false;
            break;
        }


    if(flag)
    {
        double ret = (point[N-1]-point[0]).norm();
        cout<<ret*ret;
    }
    else
    {
        polygon poly = grahamScan(point);
        double res = diameter(poly);
        cout<<res*res;
    }
}
