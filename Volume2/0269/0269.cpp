#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define EPS 1e-8
#define equals(a,b) fabs((a) - (b)) < EPS
#define PI acos(-1)

using namespace std;

struct Point
{
    double x, y;

    Point(double x=0, double y=0) : x(x), y(y) {}

    Point operator+(const Point &o) const { return Point(x+o.x, y+o.y); }

    Point operator-(const Point &o) const { return Point(x-o.x, y-o.y); }

    Point operator*(const double m) const { return Point(x*m, y*m); }

    Point operator/(const double d) const { return Point(x/d, y/d); }

    Point operator<(const Point &o) const { return x != o.x ? x < o.x : y < o.y; }

	bool operator==(const Point &o) const { return fabs(x-o.x) < EPS && fabs(y-o.y) < EPS; }

	double cross(const Point &o) const { return x * o.y - y * o.x; }

    double dot(const Point &o) const { return x * o.x + y * o.y; }

    double atan() const { return atan2(y, x); }

	double deg() const { return atan() * 180.0 / (acos(-1) * 4.0); }

    double norm() const { return sqrt(dot(*this)); }

    double distance(const Point &o) const { return (o - (*this)).norm(); }

    double area(const Point &a,const Point &b)
    {
	    Point p = a - (*this), p2 = b - (*this); 
	    return p.cross(p2);
    }

    double area_abs(const Point &a,const Point &b) const
    {
	    Point p = a - (*this), p2 = b - (*this);
	    return fabs(p.cross(p2)) / 2.0;
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

    bool hitPolygon(const Point& a,const Point& b,const Point& c)
	{
    	double t = (b-a).cross(*this-b);
    	double t2 = (c-b).cross(*this-c);
    	double t3 = (a-c).cross(*this-a);
    	if((t > 0 && t2 > 0 && t3 > 0) || ( t < 0 && t2 < 0 && t3 < 0))
    	{
    		return true;
    	}

	    return false;
    }
};

int ccw(Point a,Point b,Point c)
{
    b = b-a;
    c = c-a;

    if(b.cross(c) > 0.0) return +1;	//conter clockwise
    if(b.cross(c) < 0.0) return -1;	//clockwise
    if(b.dot(c) < 0.0) return +2;	//a on Seg(b,c)
    if(b.norm() < c.norm()) return -2;	//b on Seg(a,c)
    return 0;	//c on Seg(a,b)
}

bool inPolygon(Point p,Point a,Point b,Point c)
{
	if(ccw(a,b,p) == -1 && ccw(a,c,p) == +1) return true;

	return false;
}

double to_rad(double deg)
{
	return deg*PI/180;
}

bool hit(Point s,Point v,double d,double w,double a)
{
	if(s.distance(v) > a) return false;

	double x = a*cos(to_rad(w + d/2));
	double y = a*sin(to_rad(w + d/2));
	Point p(x,y);

	x = a*cos(to_rad(w - d/2));
	y = a*sin(to_rad(w - d/2));
	Point p2(x,y);

	if(inPolygon(v,s,s+p,s+p2)) return true;
	return false;
}

int main()
{
	int h,r;
	while(cin >> h >> r)
	{
		if(h == 0 && r == 0) break;

		vector<Point> v;
		rep(i,h)
		{
			double x,y;
			cin >> x >> y;
			v.push_back(Point(x,y));
		}

		int u,m,s;
		double du,dm,ds;
		cin >> u >> m >> s >> du >> dm >> ds;

		vector<Point> ume;
		rep(i,u)
		{
			double x,y;
			cin >> x >> y;
			ume.push_back(Point(x,y));
		}
		
		vector<Point> momo;
		rep(i,m)
		{
			double x,y;
			cin >> x >> y;
			momo.push_back(Point(x,y));
		}

		vector<Point> sakura;
		rep(i,s)
		{
			double x,y;
			cin >> x >> y;
			sakura.push_back(Point(x,y));
		}

		Point S(0,0);
		map<int,int> ma;
		rep(i,r)
		{
			int w,a;
			cin >> w >> a;

			rep(j,h)
			{
				int cnt = 0;
				if(hit(S,v[j],du,w,a)) cnt++;

				bool only = true;

				rep(k,u) if(hit(ume[k],v[j],du,w,a)) only = false;
				rep(k,m) if(hit(momo[k],v[j],dm,w,a)) only = false;
				rep(k,s) if(hit(sakura[k],v[j],ds,w,a)) only = false;

				if(cnt > 0 && only) ma[j]++;
			}
		}

		int cmax = 0;

		map<int,int>::iterator ite;
		for(ite = ma.begin();ite != ma.end();ite++)
		{
			cmax = max(cmax,ite->second);
		}

		if(cmax == 0) cout << "NA" << endl;
		else
		{
			vector<int> ans;
			for(ite = ma.begin();ite != ma.end();ite++)
			{
				if(ite->second == cmax) ans.push_back(ite->first);
			}

			sort(ans.begin(),ans.end());

			rep(i,ans.size())
			{
				cout << ans[i] + 1;
				if(i == ans.size()-1) cout << endl;
				else cout << " ";
			}
		}
	}

	return 0;
}
