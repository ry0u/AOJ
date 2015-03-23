#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30

using namespace std;

int m,n,k,d,ans;
int cost[120][120];
int dis[120][1000];
vector<int> cake;

struct Data
{
	int c,id,used;

	Data(int c,int id,int used) : c(c),id(id),used(used) {}
	
	bool operator>(const Data& data) const
	{
		return c > data.c;
	}
};

int change(string s)
{
	if(s[0] == 'H') return 0;
	else if(s[0] == 'D') return m + n + 1;
	else if(s[0] == 'C') return (s[1] - '0');
	else return (s[1] - '0') + m;
}

void dijkstra()
{
	priority_queue<Data,vector<Data>,greater<Data> > que;
	
	Data data(0,0,0);
	que.push(data);

	rep(i,120) rep(j,1000) dis[i][j] = INF;

	while(que.size())
	{
		Data data = que.top();
		que.pop();

		if(dis[data.id][data.used] <= data.c) continue;
		dis[data.id][data.used] = data.c;

		if(data.id == m + n + 1) ans = min(ans,data.c);

		rep(i,m+n+2)
		{
			if(cost[data.id][i] != INF && ( i<1 || m<i || (data.used & (1<<i)) == 0))
			{
				int ncost = data.c + cost[data.id][i];
				int nused = data.used;

				if(1 <= i && i <= m)
				{
					ncost -= cake[i-1];
					nused |= (1<<i);
				}

				if(dis[i][nused] > ncost)
				{
					que.push(Data(ncost,i,nused));
				}
			}
		}
	}
}

int main()
{
	while(cin >> m >> n >> k >> d)
	{
		if(m == 0 && n == 0 && k == 0 && d == 0) break;


		cake.clear(); 
		cake.resize(m);
		rep(i,m)
		{
			cin >> cake[i];
		}
		
		rep(i,n+m+2) rep(j,n+m+2) cost[i][j] = INF;

		
		rep(i,d)
		{
			string from,to;
			int f,t,c;

			cin >> from >> to >> c;
			
			f = change(from);
			t = change(to);

			cost[f][t] = k * c;
			cost[t][f] = k * c;
		}

		ans = INF;

		dijkstra();

		cout << ans << endl;

	}
}
