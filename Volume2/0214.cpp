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

struct Seg
{
	Point a,b;

	Seg (Point a, Point b) : a(a),b(b) {}

	bool isIntersect(const Seg& s)
	{
		if(s.a.between(a,b) || s.b.between(a,b) || a.between(s.a,s.b) || b.between(s.a,s.b))
		{
			return true;
		}
		else
		{
			return (s.a.area(a,b) * s.b.area(a,b) < -EPS && a.area(s.a,s.b) * b.area(s.a,s.b) < -EPS);
			//return ((a-b).cross(s.a-a) * (a-b).cross(s.b-a) < EPS) && ((s.b-s.a).cross(a-s.a)*(s.b-s.a).cross(b-s.a) < EPS);
		}
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
	
	bool haveCommon(const Rectangle& rec)
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

		if(c.same(rec.a)) flag = true;
		if(c.same(rec.b)) flag = true;
		if(c.same(rec.c)) flag = true;
		if(c.same(rec.d)) flag = true;
		
		return flag;
	}

	bool Rectbetween(const Point &p)
	{
		bool flag = false;

		if(p.between(s1.a,s1.b)) flag = true;
		if(p.between(s2.a,s2.b)) flag = true;
		if(p.between(s3.a,s2.b)) flag = true;
		if(p.between(s4.a,s4.b)) flag = true;

		return flag;
	}

	void print(const Point &p) const
	{
		cout << p.x << " " << p.y << endl;
	}

	bool isRectIntersect(const Rectangle& rec)
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

		if(s2.isIntersect(rec.s1)) flag = true;
		if(s2.isIntersect(rec.s2)) flag = true;
		if(s2.isIntersect(rec.s3)) flag = true;
		if(s2.isIntersect(rec.s4)) flag = true;

		if(s2.isIntersect(rec.s1)) flag = true;
		if(s2.isIntersect(rec.s2)) flag = true;
		if(s2.isIntersect(rec.s3)) flag = true;
		if(s2.isIntersect(rec.s4)) flag = true;
		
		return flag;
	}

};

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
			rep(j,m)
			{
				int xa,xb,xc,xd,ya,yb,yc,yd;
				cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;

				vector<Point> p(4);
				p[0] = Point(xa,ya);
				p[1] = Point(xb,yb);
				p[2] = Point(xc,yc);
				p[3] = Point(xd,yd);

				v.push_back(Rectangle(p[0],p[1],p[2],p[3]));

				if(j == 0) ans++;
				else
				{
					Rectangle rec = v[j];

					bool flag = true;
					rep(k,v.size()-1)
					{
						if(rec.haveCommon(v[k])) 
						{
							flag = false;
							break;
						}

						if(rec.Rectbetween(v[k]))
						{
							flag = false;
							break;
						}

						rec.print(v[k]);
					}
					
					rep(k,v.size()-1)
					{
						if(rec.isRectIntersect(v[k]))
						{
							flag = false;
							break;
						}
						else
						{
							bool in1 = false,in2 = false,in3 = false,in4 = false;
							
							Point p(rec.a.x,rec.a.y+2010);
							Seg seg(rec.a,p);
							int cnt = 0;

							
							if(seg.isIntersect(v[k].s1)) 
							{
								cnt++;
							}
							if(seg.isIntersect(v[k].s2)) 
							{
								cnt++;
							}
							if(seg.isIntersect(v[k].s3)) 
							{
								cnt++;
							}
							if(seg.isIntersect(v[k].s4))
							{
								cnt++;
							}

							if(v[k].a.between(seg.a,seg.b)) cnt--;
							if(v[k].b.between(seg.a,seg.b)) cnt--;
							if(v[k].c.between(seg.a,seg.b)) cnt--;
							if(v[k].d.between(seg.a,seg.b)) cnt--;
							
							if(cnt == 1) in1 = true;

						   	p = Point(rec.b.x,rec.b.y+2010);
							seg = Seg(rec.b,p);
							cnt = 0;

							if(seg.isIntersect(v[k].s1)) cnt++;
							if(seg.isIntersect(v[k].s2)) cnt++;
							if(seg.isIntersect(v[k].s3)) cnt++;
							if(seg.isIntersect(v[k].s4)) cnt++;

							if(v[k].a.between(seg.a,seg.b)) cnt--;
							if(v[k].b.between(seg.a,seg.b)) cnt--;
							if(v[k].c.between(seg.a,seg.b)) cnt--;
							if(v[k].d.between(seg.a,seg.b)) cnt--;

							if(cnt == 1) in2 = true;

							p = Point(rec.c.x,rec.c.y+2010);
							seg = Seg(rec.c,p);
							cnt = 0;
						
							if(seg.isIntersect(v[k].s1)) cnt++;
							if(seg.isIntersect(v[k].s2)) cnt++;
							if(seg.isIntersect(v[k].s3)) cnt++;
							if(seg.isIntersect(v[k].s4)) cnt++;

							if(v[k].a.between(seg.a,seg.b)) cnt--;
							if(v[k].b.between(seg.a,seg.b)) cnt--;
							if(v[k].c.between(seg.a,seg.b)) cnt--;
							if(v[k].d.between(seg.a,seg.b)) cnt--;

							if(cnt == 1) in3 = true;

							p = Point(rec.d.x,rec.d.y+2010);
							seg = Seg(rec.d,p);
							cnt = 0;

							if(seg.isIntersect(v[k].s1)) cnt++;
							if(seg.isIntersect(v[k].s2)) cnt++;
							if(seg.isIntersect(v[k].s3)) cnt++;
							if(seg.isIntersect(v[k].s4)) cnt++;

							if(v[k].a.between(seg.a,seg.b)) cnt--;
							if(v[k].b.between(seg.a,seg.b)) cnt--;
							if(v[k].c.between(seg.a,seg.b)) cnt--;
							if(v[k].d.between(seg.a,seg.b)) cnt--;
							
							if(cnt == 1) in4 = true;

							if(in1 && in2 && in3 && in4)
							{
								flag = false;
								break;
							}
							else if(!in1 && !in2 && !in3 && !in4)
							{
								p = Point(v[k].a.x,v[k].a.y+2010);
								seg = Seg(v[k].a,p);
								cnt = 0;

								if(seg.isIntersect(Seg(rec.a,rec.b))) cnt++; 
								if(seg.isIntersect(Seg(rec.b,rec.c))) cnt++;
								if(seg.isIntersect(Seg(rec.c,rec.d))) cnt++;
								if(seg.isIntersect(Seg(rec.d,rec.a))) cnt++;

								if(rec.a.between(seg.a,seg.b)) cnt--;  
								if(rec.b.between(seg.a,seg.b)) cnt--;
								if(rec.c.between(seg.a,seg.b)) cnt--;
								if(rec.d.between(seg.a,seg.b)) cnt--;
								
								if(cnt == 1) in1 = true;

								p = Point(v[k].b.x,v[k].b.y+2010);
								seg = Seg(v[k].b,p);
								cnt = 0;

								if(seg.isIntersect(Seg(rec.a,rec.b))) cnt++;
								if(seg.isIntersect(Seg(rec.b,rec.c))) cnt++;
								if(seg.isIntersect(Seg(rec.c,rec.d))) cnt++;
								if(seg.isIntersect(Seg(rec.d,rec.a))) cnt++;
								
								if(rec.a.between(seg.a,seg.b)) cnt--;
								if(rec.b.between(seg.a,seg.b)) cnt--;
								if(rec.c.between(seg.a,seg.b)) cnt--;
								if(rec.d.between(seg.a,seg.b)) cnt--;
								

								if(cnt == 1) in2 = true;

								p = Point(v[k].c.x,v[k].c.y+2010);
								seg = Seg(v[k].c,p);
								cnt = 0;

								if(seg.isIntersect(Seg(rec.a,rec.b))) cnt++;
								if(seg.isIntersect(Seg(rec.b,rec.c))) cnt++;
								if(seg.isIntersect(Seg(rec.c,rec.d))) cnt++;
								if(seg.isIntersect(Seg(rec.d,rec.a))) cnt++;
								
								if(rec.a.between(seg.a,seg.b)) cnt--;
								if(rec.b.between(seg.a,seg.b)) cnt--;
								if(rec.c.between(seg.a,seg.b)) cnt--;
								if(rec.d.between(seg.a,seg.b)) cnt--;

								if(cnt == 1) in3 = true;

								p = Point(v[k].d.x,v[k].d.y+2010);
								seg = Seg(v[k].d,p);
								cnt = 0;

								if(seg.isIntersect(Seg(rec.a,rec.b))) cnt++;
								if(seg.isIntersect(Seg(rec.b,rec.c))) cnt++;
								if(seg.isIntersect(Seg(rec.c,rec.d))) cnt++;
								if(seg.isIntersect(Seg(rec.d,rec.a))) cnt++;
								
								if(rec.a.between(seg.a,seg.b)) cnt--;
								if(rec.b.between(seg.a,seg.b)) cnt--;
								if(rec.c.between(seg.a,seg.b)) cnt--;
								if(rec.d.between(seg.a,seg.b)) cnt--;

								if(cnt == 1) in4 = true;

								if(in1 && in2 && in3 && in4) 
								{
									flag = false;
									break;
								}
							}
						}
					}

					if(flag) ans++;
				}
			}

			cout << ans << endl;
		}
	}
}
