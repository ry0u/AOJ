#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int X,Y,Z;
vector<int> r;


struct Squares
{
	int cost;
	int next;

	Squares()
	{
		cost = 0;
		next = 0;
	}

	Squares(int c,int n)
	{
		cost = c;
		next = n;
	}
};

vector<Squares> f;
double ans = 0;
double memo[51][5000];


void dfs(int now,int cost,int turn)
{
	if(now >= Y)
	{
		double ret = 1;
		rep(i,turn) ret *= (1.0 / r.size());
		ans += cost * ret;
		return;
	}

	rep(i,r.size())
	{
		int next = now + r[i] + f[now + r[i]].next;
		int ncost = cost + f[now + r[i]].cost;

		if(ncost < 0) ncost = 0;
		if(next > Y) next = Y;

		if(memo[next][ncost] == -1)
		{
			dfs(next,ncost,turn+1);
			memo[next][ncost] = ans;
		}
		else
		{	
			ans += memo[next][ncost];
			return;
		}
	}
}

int main()
{
	while(cin >> X >> Y >> Z)
	{
		if(X == 0 && Y == 0 && Z == 0) break;

		r.clear();
		f.clear();
		ans = 0;

		rep(i,X)
		{
			int temp;
			cin >> temp;
			r.push_back(temp);
		}

		rep(i,Y+1) f.push_back(Squares());

		rep(i,Z)
		{
			int n,e,a;
			cin >> n >> e >> a;
			
			if(e == 1) f[n].next = a;
			else if(e == 2) f[n].cost = a;
			else if(e == 3) f[n].cost = -a;
		}

		rep(i,51) rep(j,5000) memo[i][j] = -1;

		
		dfs(0,0,0);

		rep(i,Y+1)
		{
			rep(j,101)
			{
				cout << memo[i][j] << " ";
			}
			cout << endl;
		}

		cout << (int) ans << endl;
	}
	return 0;
}
