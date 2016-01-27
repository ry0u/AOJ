#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1 << 28
#define EPS 1e-10

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
	//線分abが自身の含まれているのかどうか判断する
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

double cost[1000][1000];
bool used[1000];
int d[1000];
int prev[1000];

void dijkstra(int s,int n)
{
	fill(d,d+n,INF);
	fill(used,used+n,false);
	fill(prev,prev+n,-1);
	d[s] = 0;
	
	while(true)
	{
		int v = -1;

		rep(u,n)
		{
			if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
		}

		if(v == -1) break;
		used[v] = true;

		rep(u,n)
		{
			if(d[u] > d[v] + cost[v][u])
			{
				d[u] = d[v] + cost[v][u];
				prev[u] = v;
			}
		}
	}
}

vector<int> get_path(int t)
{
	vector<int> path;

	for(;t != -1;t = prev[t]) path.push_back(t);
	reverse(path.begin(),path.end());
	return path;
}

int main()
{
	int n;
	while(cin >> n && n)
	{
		vector<Point> p;
		vector<int> number;
		
		rep(i,1000) rep(j,1000) cost[i][j] = INF;

		rep(i,n)
		{
			int num,a,b;
			cin >> num >> a >> b;

			p.push_back(Point(a,b));
			number.push_back(num);
		}

		rep(i,n)
		{
			REP(j,i+1,n)
			{
				if(p[i].distance(p[j]) <= 50.0)
				{
					cost[i][j] = p[i].distance(p[j]);
					cost[j][i] = p[j].distance(p[i]);
				}
			}
		}

		int m;
		cin >> m;

		rep(i,m)
		{
			int from,to;
			cin >> from >> to;

			rep(j,n)
			{
				if(from == number[j])
				{
					from = j;
					break;
				}
			}
			rep(j,n)
			{
				if(to == number[j])
				{
					to = j;
					break;
				}
			}

			dijkstra(from,n);

			if(d[to] == INF)
			{
				cout << "NA" << endl;
			}
			else
			{
				vector<int> ans = get_path(to);
				bool flag = true;
				rep(k,ans.size())
				{
					if(flag) flag = false;
					else cout << " ";

					cout << number[ans[k]];
				}
				cout << endl;
			}
		}
	}
	return 0;
}
