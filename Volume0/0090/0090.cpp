#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <complex>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair
#define EPS 1e-8
#define equals(a,b) fabs((a) - (b)) < EPS

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

struct Point {
    double x, y;

    Point(double x=0, double y=0) : x(x), y(y) {}

    Point operator+(const Point &o) const { return Point(x+o.x, y+o.y); }

    Point operator-(const Point &o) const { return Point(x-o.x, y-o.y); }

    Point operator*(const double m) const { return Point(x*m, y*m); }

    Point operator/(const double d) const { return Point(x/d, y/d); }

    bool operator<(const Point &o) const { return x != o.x ? x < o.x : y < o.y; }

    bool operator==(const Point &o) const { return fabs(x-o.x) < EPS && fabs(y-o.y) < EPS; }

    double cross(const Point &o) const { return x * o.y - y * o.x; }

    double dot(const Point &o) const { return x * o.x + y * o.y; }

    double atan() const { return atan2(y, x); }

    double norm() const { return sqrt(dot(*this)); }

    double distance(const Point &o) const { return (o - (*this)).norm(); }

    double area(const Point &a,const Point &b) {
        Point p = a - (*this), p2 = b - (*this); 
        return p.cross(p2);
    }

    double area_abs(const Point &a,const Point &b) const {
        Point p = a - (*this), p2 = b - (*this);
        return fabs(p.cross(p2)) / 2.0;
    }	

    //線分abが自身に含まれているのかどうか判断する
    int between(const Point &a,const Point &b) {
        if(area(a,b) != 0) return 0;

        if(a.x != b.x)  return ((a.x <= x) && (x <= b.x) || (a.x >= x) && (x >= b.x));
        else return ((a.y <= y) && (y <= b.y) || (a.y >= y) && (y >= b.y));
    }      

    double distance_seg(const Point& a,const Point& b) {
        if((b-a).dot(*this-a) < EPS) {
            return (*this-a).norm();
        }
        if((a-b).dot(*this-b) < EPS) {
            return (*this-b).norm();
        }
        return abs((b-a).cross(*this-a)) / (b-a).norm();
    }

    bool hitPolygon(const Point& a,const Point& b,const Point& c) {
        double t = (b-a).cross(*this-b);
        double t2 = (c-b).cross(*this-c);
        double t3 = (a-c).cross(*this-a);	

        if((t > 0 && t2 > 0 && t3 > 0) || ( t < 0 && t2 < 0 && t3 < 0)) {
            return true;
        }

        return false;
    }
};

struct Circle {
    Point p;
    double r;

    Circle() : p(Point(0,0)), r(0) {}

    Circle(Point o, double r) : p(o), r(r) {}

    Circle(double x,double y, double r) : p(Point(x,y)), r(r) {}

    bool isCircleIn(const Point& o) {
        double dist = p.distance(o);
        return dist < r + EPS;
    }

    // 1:外で接する，0:交差なし，-1:内で接する，2:交差，-2:内包
    int isIntersect(const Circle& c) {
        double d = (c.p - p).dot(c.p - p);
        double len = (c.r + r) * (c.r + r);

        if(equals(d,len)) return 1;
        if(d > len) return 0;

        double R = fabs(c.r - r) * fabs(c.r - r);
        if(equals(d,R)) return -1;
        if(d > R) return 2;
        return -2;
    }

    vector<Point> getCrossPoint(const Circle& c) {
        vector<Point> ret;
        int ch = isIntersect(c);

        if(ch == 0 || ch == -2) return ret;

        Point base = c.p - p;
        double len = base.dot(base);
        double t = (r*r - c.r*c.r + len) / (2.0 * len);

        if(ch == 2) {
            Point n(-base.y,base.x);
            n = n / (n.norm());
            double h = sqrt(r * r - t*t*len);

            ret.push_back(p + (base*t) + (n*h));
            ret.push_back(p + (base*t) - (n*h));
        } else {
            ret.push_back(p + (base*t));
        }

        return ret;
    }

};

int main() {
    int n;

    while(cin >> n && n) {
        double x,y;
        char c;

        vector<Circle> v;

        rep(i,n) {
            cin >> x >> c >> y;
            v.push_back(Circle(x,y,1));
        }

        vector<Point> crossPoints;
        rep(i,n) {
            REP(j,i+1,n) {
                vector<Point> res = v[i].getCrossPoint(v[j]);
                rep(k,res.size()) {
                    crossPoints.push_back(res[k]);
                }
            }
        }

        // cout << "----crossPoint:" << crossPoints.size() << endl;
        // rep(i,crossPoints.size()) {
        //     Point p = crossPoints[i];
        //     cout << p.x << " " << p.y << endl;
        // }

        int ans = 1;
        rep(i,crossPoints.size()) {
            int cnt = 0;
            rep(j,n) {
                if(v[j].isCircleIn(crossPoints[i])) {
                    cnt++;
                }
            }

            ans = max(ans,cnt);
        }

        cout << ans << endl;
    }


    return 0;
}
