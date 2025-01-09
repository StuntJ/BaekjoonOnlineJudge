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
    vector2 normalize() const { return vector2(x/norm(), y/norm()); }

    double polar() const { return fmod(atan2(y,x)+PI*2,PI*2); }

    double dot(const vector2 &rhs) const
    {
        return x*rhs.x+ y*rhs.y;
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

typedef vector<vector2> polygon;

double ccw(vector2 a, vector2 b)
{
    return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b)
{
    return ccw(a-p,b-p);
}

vector2 minE;
bool compare(vector2 a, vector2 b)
{
    double res = ccw(minE,a,b);
    if(fabs(res)<DBL_EPSILON) return (a-minE).norm() < (b-minE).norm();
    return res>0;
}

polygon grahamScan(vector<vector2> &points)
{
    sort(points.begin(),points.end());
    minE = points[0];
    sort(points.begin()+1,points.end(),compare);

    stack<vector2> st;
    st.push(minE);
    st.push(points[1]);
    int idx = 2;
    while(idx<points.size())
    {
        vector2 a,b;
        while(st.size()>=2)
        {
            b = st.top();
            st.pop();
            a = st.top();
            if(ccw(a,b,points[idx])>0)
            {
                st.push(b);
                break;
            }
        }
        st.push(points[idx++]);
    }


    polygon res;
    while(!st.empty())
    {
        res.emplace_back(st.top());
        st.pop();
    }
    return res;
}

pair<int,int> diameter(const polygon &p)
{
    int n = p.size();

    int left = min_element(p.begin(),p.end()) - p.begin();
    int right = max_element(p.begin(),p.end()) - p.begin();

    vector2 calipersA(0,1);
    double ret = (p[right]-p[left]).norm();
    pair<int,int> ans = make_pair(right,left);
    vector<vector2> toNext(n);
    for(int i=0;i<n;i++)
        toNext[i] = (p[(i+1)%n]-p[i]).normalize();

    int a = left, b = right;
    while(a!=right||b!=left)
    {
        double cosThetaA = calipersA.dot(toNext[a]);
        double cosThetaB = -calipersA.dot(toNext[b]);
        if(cosThetaA>cosThetaB) //A가 각도 작음
        {
            calipersA = toNext[a];
            a = (a+1)%n;
        }
        else
        {
            calipersA = toNext[b]*(-1);
            b = (b+1)%n;
        }
        if(ret<(p[a]-p[b]).norm())
        {
            ans = make_pair(a,b);
            ret = (p[a]-p[b]).norm();
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout<<fixed;
    cout.precision(0);
    int T;
    cin>>T;

    for(int t=0;t<T;t++)
    {
        int N;
        cin>>N;
        vector<vector2> points(N);

        for(int i=0;i<N;i++)
            cin>>points[i].x>>points[i].y;

        bool flag = true;
        for(int i=2;i<N;i++)
            if(fabs(ccw(points[i-2],points[i-1],points[i]))>=DBL_EPSILON)
            {
                flag = false;
                break;
            }

        if(flag)
        {
            sort(points.begin(),points.end());
            cout<<points[0].x<<' '<<points[0].y<<' '<<points[N-1].x<<' '<<points[N-1].y<<'\n';
            continue;
        }


        polygon c_hull = grahamScan(points);

        pair<int,int> ans = diameter(c_hull);
        cout<<c_hull[ans.first].x<<' '<<c_hull[ans.first].y<<' '<<c_hull[ans.second].x<<' '<<c_hull[ans.second].y<<'\n';
    }

}
