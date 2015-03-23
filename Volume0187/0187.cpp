#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define EPS 1e-8

using namespace std;

struct Point
{
	double x, y;

	Point(double x=0, double y=0) : x(x), y(y) {}

	double distance (const Point &o) const
	{
		return sqrt((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y));
	}

	Point operator+(const Point &o) const
	{
		return Point(x+o.x, y+o.y);
	}

	Point operator-(const Point &o) const
	{
		return Point(x-o.x, y-o.y);
	}

	Point operator*(const double m) const
	{
		return Point(x*m, y*m);
	}

	Point operator/(const double d) const
	{
		return Point(x/d, y/d);
	}

	double cross(const Point &o) const
	{
		return x * o.y - y * o.x;
	}

	double dot(const Point &o) const
	{
		return x * o.x + y * o.y;
	}

	double atan() const
	{
		return atan2(y, x);
	}

	double norm() const
	{
		return sqrt(dot(*this));
	}

	double area_abs(const Point &a,const Point &b) const
	{
		double t = (a.x - x) * (b.y - y);
		double t2 = (a.y - y) * (b.x - x);
		double areas = abs(t-t2);
		return areas/2;
	}

	//符号付き面積
	double area(const Point &a,const Point &b)
	{
		return ((a.x - x) * (b.y - y)) + ((b.x - x) * (y - a.y));
	}

	//線分abが自身に含まれているのかどうか判断する
	int between(const Point &a,const Point &b)
	{
		if(area(a,b) != 0) return 0;

		if(a.x != b.x)
		{
			return ((a.x <= x) && (x <= b.x) || (a.x >= x) && (x >= b.x));
		}
		else
		{
			return ((a.y <= y) && (y <= b.y) || (a.y >= y) && (y >= b.y));
		}
	}

	double distance_seg(const Point& a,const Point& b)
	{
		if((b-a).dot(*this-a) < EPS)
		{
			return (*this-a).norm();
		}
		if((a-b).dot(*this-b) < EPS)
		{
			return (*this-b).norm();
		}
		return abs((b-a).cross(*this-a)) / (b-a).norm();
	}

	//点a,b,cからなる三角形の中に自身が含まれているかどうか
	bool hitPolygon(const Point& a,const Point& b,const Point& c)
	{
		double t = (b-a).cross(*this-b);
		double t2 = (c-b).cross(*this-c);
		double t3 = (a-c).cross(*this-a);
		if((t > 0 && t2 > 0 && t3 > 0) || ( t < 0 && t2 < 0 && t3 < 0))
		{
			return 1;
		}

		return 0;
	}
};

struct Seg
{
	Point a,b;

	Seg (Point a, Point b) : a(a),b(b) {}

	bool isIntersect(Seg &s)
	{
		if(s.a.between(a,b) || s.b.between(a,b) || a.between(s.a,s.b) || b.between(s.a,s.b))
		{
			return true;
		}

		return ((a-b).cross(s.a-a) * (a-b).cross(s.b-a) < EPS) && ((s.b-s.a).cross(a-s.a)*(s.b-s.a).cross(b-s.a) < EPS);
	}

   	Point getCrossPoint(Seg &s)
	{
		Point p = s.b - s.a;
		double d = abs(p.cross(a-s.a));
		double d2 = abs(p.cross(b-s.a));

		double t = d / (d+d2);
		return a + (b-a)*t;
	}

};

double polygonArea(const vector<Point>& p)
{
    int n = p.size();
    double ret = 0.0;
    for(int i=0; i<n; ++i)
        ret += p[i].cross(p[(i+1)%n]);
    return abs(ret) / 2.0;
}

int main()
{
	double xa,ya,xb,yb;
	while(cin >> xa >> ya >> xb >> yb)
	{
		if(xa == 0 && ya == 0 && xb == 0 && yb == 0) break;

		vector<Seg> v;
		v.push_back(Seg(Point(xa,ya),Point(xb,yb)));

		rep(i,2)
		{
			cin >> xa >> ya >> xb >> yb;
			v.push_back(Seg(Point(xa,ya),Point(xb,yb)));
		}
		
		bool flag = false;
		if(!v[0].isIntersect(v[1])) flag = true;
		if(!v[1].isIntersect(v[2])) flag = true;
		if(!v[2].isIntersect(v[0])) flag = true;

		if(flag) cout << "kyo" << endl;
		else
		{
			vector<Point> p;
			rep(i,3)
			{
				p.push_back(v[i].getCrossPoint(v[(i+1)%3]));
			}

			double ret = polygonArea(p);
			if(ret >= 1900000.0)
			{
				cout << "dai-kichi" << endl;
			}
			else if(ret >= 1000000.0)
			{
				cout << "chu-kichi" << endl;
			}
			else if(ret >= 100000.0)
			{
				cout << "kichi" << endl;
			}
			else if(ret > EPS)
			{
				cout << "syo-kichi" << endl;
			} 
			else cout << "kyo" << endl;
		}
	}	
	return 0;
}
