#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

struct Item
{
	int id;
	int cost;
	int start,end;

	Item(int i,int c,int s,int e)
	{
		id = i;
		cost = c;
		start = s;
		end = e;
	}
};

bool used[101][101];
int h,w,sy,sx,ans;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
vector<vector<string> > field;
vector<Item> v;

void dfs(int turn,int y,int x,int cost,vector<bool> can)
{
	/*
	cout << turn << " " << y << " " << x << " " << cost << endl;
	rep(i,h)
	{
		rep(j,w)
		{
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
	*/ 

	cout << turn << " ";
	rep(i,can.size())
	{
		if(can[i]) cout << "O ";
		else cout << "X ";
	}
	cout << endl;

	rep(i,4)
	{
		int cany = y + dy[i];
		int canx = x + dx[i];

		if(0 <= cany && cany < h && 0 <= canx && canx < w)
		{
			int id = atoi(field[cany][canx].c_str());
			if(!can[id])
			{
				rep(j,v.size()) 
				{
					if(v[j].id == id && v[i].start <= turn && turn < v[i].end) 
					{
						can[id] = true;
						cout << cost << " getItem:" << v[i].id << endl;
						cost += v[j].cost;
					}
				}
			}
		}
	}

	ans = max(ans,cost);
	
	rep(i,4)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(0 <= ny && ny < h && 0 <= nx && nx < w && !used[ny][nx] && field[ny][nx] == ".")
		{
			used[ny][nx] = true;

			dfs(turn+1,ny,nx,cost,can);
		}
	}

}

int main()
{
	while(cin >> w >> h)
	{
		if(h == 0 & w == 0) break;

		rep(i,101) rep(j,101) used[i][j] = false;

		field.resize(h);
		rep(i,h) 
		{
			field[i].clear();
			field[i].resize(w);
		}

		rep(i,h)
		{
			rep(j,w)
			{
				cin >> field[i][j];
				if(field[i][j] == "P")
				{
					sy = i;
					sx = j;
				}
			}
		}

		int n;
		cin >> n;
		
		v.clear();
		rep(i,n)
		{
			int g,d,s,e;
			cin >> g >> d >> s >> e;
			v.push_back(Item(g,d,s,e));
		}	
		
		ans = 0;
		vector<bool> can(10);
		rep(i,10) can[i] = false;

		dfs(0,sy,sx,0,can);

		cout << ans << endl;
	}
}
