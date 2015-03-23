#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define EPS 1e-8
#define PI acos(-1)

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

	bool operator<(const Point &o) const
	{
		if(x != o.x) x < o.x;
		else y < o.y;
		
	}

	bool operator>(const Point &o) const
	{
		if(x != o.x) x > o.x;
		else y > o.y;
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
	double area(const Point &a,const Point &b) const
	{
		return ((a.x - x) * (b.y - y)) + ((b.x - x) * (y - a.y));
	}

	//線分abが自身に含まれているのかどうか判断する
	int between(const Point &a,const Point &b) const
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

	bool same(const Point& a)
	{
		if(x == a.x && y == a.y) return true;
		else return false;
	}
};

int ccw(const Point &a,const Point &b,const Point &c)
{
	Point p1 = b - a;
	Point p2 = c -a;
	if (p1.cross(p2) > 0)   return +1;       // counter clockwise
	if (p1.cross(p2) < 0)   return -1;       // clockwise
	if (p1.dot(p2) < 0)     return +2;       // c--a--b on line
	if (p1.norm() < p2.norm()) return -2;       // a--b--c on line
	return 0;
}

bool cmp(Point a,Point b)
{
	return a.atan() < b.atan();
}

struct Seg
{
	Point a,b;

	Seg (Point a, Point b) : a(a),b(b) {}
	
	/*
	bool isIntersect(const Seg& s) const
	{
		if(s.a.between(a,b) || s.b.between(a,b) || a.between(s.a,s.b) || b.between(s.a,s.b))
		{
			return true;
		}
		else
		{
			//return (s.a.area(a,b) * s.b.area(a,b) < -EPS && a.area(s.a,s.b) * b.area(s.a,s.b) < -EPS);
			return ((a-b).cross(s.a-a) * (a-b).cross(s.b-a) < EPS) && ((s.b-s.a).cross(a-s.a)*(s.b-s.a).cross(b-s.a) < EPS);
		}
	}
	*/

	bool isIntersect(const Seg &s) const
	{
		return ccw(a,b,s.a) * ccw(a,b,s.b) <= 0 && ccw(s.a,s.b,a) * ccw(s.a,s.b,b) <= 0;
	}

	int getCrossPoint(const Seg& s,Point& p)
	{
		Point ac = s.a - a;
		int sw = -1;

		double temp = (b.x - a.x) * (s.b.y - s.a.y) - (b.y - a.y) * (s.b.x - s.a.x);

		if(fabs(temp) > EPS)
		{
			double r = ((s.b.y - s.a.y) * p.x - (s.b.x - s.a.y) * p.y) / temp;
			double s = ((b.y - a.y) * p.x - (b.x - a.x) * p.y) / temp;
			if(r > -EPS && r < 1.0 + EPS && s > -EPS && s < 1.0 + EPS)
			{
				p.x = a.x + r * (b.x - a.x);
				p.y = a.y + r * (b.y - a.y);
				sw = 1;
			}
			else sw = 0;
		}
		return sw;	
	}

};

struct Rectangle
{
	Point a,b,c,d;
	Seg s1,s2,s3,s4;

	Rectangle(Point a,Point b,Point c,Point d) : a(a),b(b),c(c),d(d),s1(Seg(a,b)),s2(Seg(b,c)),s3(Seg(c,d)),s4(Seg(d,a)) {}
	
	bool haveCommon(const Rectangle &rec)
	{
		bool flag = false;

		if(a.same(rec.a)) flag = true;
		if(a.same(rec.b)) flag = true;
		if(a.same(rec.c)) flag = true;
		if(a.same(rec.d)) flag = true;

		if(b.same(rec.a)) flag = true;
		if(b.same(rec.b)) flag = true;
		if(b.same(rec.c)) flag = true;
		if(b.same(rec.d)) flag = true;

		if(c.same(rec.a)) flag = true;
		if(c.same(rec.b)) flag = true;
		if(c.same(rec.c)) flag = true;
		if(c.same(rec.d)) flag = true;

		if(d.same(rec.a)) flag = true;
		if(d.same(rec.b)) flag = true;
		if(d.same(rec.c)) flag = true;
		if(d.same(rec.d)) flag = true;
		
		return flag;
	}

	bool Rectbetween(const Point &p)
	{
		bool flag = false;

		if(p.between(s1.a,s1.b)) flag = true;
		if(p.between(s2.a,s2.b)) flag = true;
		if(p.between(s3.a,s3.b)) flag = true;
		if(p.between(s4.a,s4.b)) flag = true;

		return flag;
	}

	bool isRectIntersect(const Rectangle &rec)
	{
		bool flag = false;
		
		if(s1.isIntersect(rec.s1)) flag = true;
		if(s1.isIntersect(rec.s2)) flag = true;
		if(s1.isIntersect(rec.s3)) flag = true;
		if(s1.isIntersect(rec.s4)) flag = true;

		if(s2.isIntersect(rec.s1)) flag = true;
		if(s2.isIntersect(rec.s2)) flag = true;
		if(s2.isIntersect(rec.s3)) flag = true;
		if(s2.isIntersect(rec.s4)) flag = true;

		if(s3.isIntersect(rec.s1)) flag = true;
		if(s3.isIntersect(rec.s2)) flag = true;
		if(s3.isIntersect(rec.s3)) flag = true;
		if(s3.isIntersect(rec.s4)) flag = true;

		if(s4.isIntersect(rec.s1)) flag = true;
		if(s4.isIntersect(rec.s2)) flag = true;
		if(s4.isIntersect(rec.s3)) flag = true;
		if(s4.isIntersect(rec.s4)) flag = true;
		
		return flag;
	}

   	bool contains(const Point& p) {
  		bool in = false;

		Point p1 = a - p;
		Point p2 = b - p;

		if(p1.y > p2.y) swap(p1,p2);
		if(p1.y <= 0 && 0 < p2.y)
		{
			if(p1.cross(p2) < 0) in = !in;
		}
		if(p1.cross(p2) == 0 && p1.dot(p2) <= 0) return true;
		
		p1 = b - p;
		p2 = c - p;

		if(p1.y > p2.y) swap(p1,p2);
		if(p1.y <= 0 && 0 < p2.y)
		{
			if(p1.cross(p2) < 0) in = !in;
		}
		if(p1.cross(p2) == 0 && p1.dot(p2) <= 0) return true;

		p1 = c - p;
		p2 = d - p;

		if(p1.y > p2.y) swap(p1,p2);
		if(p1.y <= 0 && 0 < p2.y)
		{
			if(p1.cross(p2) < 0) in = !in;
		}
		if(p1.cross(p2) == 0 && p1.dot(p2) <= 0) return true;

		p1 = d - p;
		p2 = a - p;

		if(p1.y > p2.y) swap(p1,p2);
		if(p1.y <= 0 && 0 < p2.y)
		{
			if(p1.cross(p2) < 0) in = !in;
		}
		if(p1.cross(p2) == 0 && p1.dot(p2) <= 0) return true;

		if(in)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int par[101];
int rank[101];

void init(int n)
{
	rep(i,n)
	{
		par[i]=i;
		rank[i] = 0;
	}
}

int find(int x)
{
	if(par[x] == x) return x;
	else return par[x] = find(par[x]);
}

void unite(int x,int y)
{
	x = find(x);
	y = find(y);

	if(x == y) return;

	if(rank[x] < rank[y])
	{
		par[x] = y;
	}
	else
	{
		par[y] = x;
		if(rank[x] == rank[y]) rank[x]++;
	}
}

bool same(int x,int y)
{
	return find(x) == find(y);
}


int main()
{
	int n;

	while(cin >>n && n)
	{
		rep(i,n)
		{
			int m;
			cin >> m;

			vector<Rectangle> v;
			int ans = 0;
			init(m);

			rep(j,m)
			{
				int xa,xb,xc,xd,ya,yb,yc,yd;
				cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;

				vector<Point> p(4);
				p[0] = Point(xa,ya);
				p[1] = Point(xb,yb);
				p[2] = Point(xc,yc);
				p[3] = Point(xd,yd);

				sort(p.begin(),p.end(),cmp);

				v.push_back(Rectangle(p[0],p[1],p[2],p[3]));

				Rectangle rec = v[j];

				bool flag = true;
				rep(k,v.size()-1)
				{
					if(rec.haveCommon(v[k])) 
					{
						unite(k,j);
					}
					else if(rec.Rectbetween(v[k].a) || rec.Rectbetween(v[k].b) || rec.Rectbetween(v[k].c) || rec.Rectbetween(v[k].d))
					{
						unite(k,j);
					}
					else if(rec.isRectIntersect(v[k]))
					{
						unite(k,j);
					}
					else
					{
						bool in1 = false,in2 = false,in3 = false,in4 = false;
						
						if(v[k].contains(rec.a)) in1 = true;
						if(v[k].contains(rec.b)) in2 = true;
						if(v[k].contains(rec.c)) in3 = true;
						if(v[k].contains(rec.d)) in4 = true;

						if(in1 && in2 && in3 && in4)
						{
							unite(k,j);
						}
						else if(!in1 && !in2 && !in3 && !in4)
						{
							if(rec.contains(v[k].a)) in1 = true;
							if(rec.contains(v[k].b)) in2 = true;
							if(rec.contains(v[k].c)) in3 = true;
							if(rec.contains(v[k].d)) in4 = true;

							if(in1 && in2 && in3 && in4) 
							{
								unite(k,j);
							}
						}
					}
				}
			}

			vector<bool> ret;
			ret.resize(m);

			rep(j,m) ret[j] = false;

			rep(j,m) ret[find(j)] = true;

			rep(j,m) if(ret[j]) ans++;
			cout << ans << endl;
		}
	}
}
