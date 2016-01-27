#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30

using namespace std;
typedef pair<int,int> P;

struct edge
{
	int to;
	int cost;
   	int free;

	edge(int t,int c,int f)
	{
		to = t;
		cost = c;
		free = f;
	}

	bool operator>(const edge &e) const
	{
		return cost > e.cost;
	}
};


vector<edge> G[101];
int d[101][2];
bool used[101][2];

void dijkstra(int s,int n)
{
	priority_queue<edge,vector<edge>,greater<edge> > que;
	rep(i,101) rep(j,2) d[i][j] = INF;

	rep(i,101) rep(j,2) used[i][j] = false;

	d[s][1] = 0;
	que.push(edge(0,s,1));

	while(que.size())
	{
	   	edge p = que.top();
		que.pop();


		int v = p.to;

		if(used[v][p.free]) continue;
		used[v][p.free] = true;

		if(d[p.to][p.free] < p.cost) continue;

		rep(i,G[v].size())
		{
			edge e = G[v][i];

			if(p.free - e.free >= 0)
			{
				if(d[e.to][p.free-e.free] > p.cost + e.cost)
				{
					d[e.to][p.free-e.free] = p.cost + e.cost;
					que.push(edge(e.to,p.cost + e.cost,p.free-e.free));
				}
			}
		}
	}
}

int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) break;

			
		rep(i,100) G[i].clear();

		rep(i,m)
		{
			int a,b,c;
			cin >> a >> b >> c;

			a--;
			b--;

			G[a].push_back(edge(b,c,0));
			G[b].push_back(edge(a,c,0));
		}

		vector<P> v;
		rep(i,n)
		{
			rep(j,G[i].size())
			{
				rep(k,G[G[i][j].to].size()) 
				{
					if(i != G[G[i][j].to][k].to) v.push_back(P(i,G[G[i][j].to][k].to));
				}
			}
		}

		rep(i,v.size()) if(v[i].first > v[i].second) swap(v[i].first,v[i].second);
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());

		rep(i,v.size())
		{
			G[v[i].first].push_back(edge(v[i].second,0,1));
			G[v[i].second].push_back(edge(v[i].first,0,1));
		}

		dijkstra(0,n);

		cout << min(d[n-1][1],d[n-1][0]) << endl;
	}
}
