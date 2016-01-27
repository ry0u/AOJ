#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30

using namespace std;

int n;
vector<int> v,v2;
bool used[101],used2[101];

int getNext(int y,int type)
{
	if(type == 0)
	{
		if(v[y] == 2)
		{
			while(y-1 >= 0 && v[y] == 2) y--;
		}
		if(v[y] == 1)
		{
			while(y+1 < n && v[y+1] == 1) y++;
		}
		return y;
	}
	else
	{
		if(v2[y] == 2)
		{
			while(y-1 >= 0 && v2[y] == 2) y--;
		}
		if(v2[y] == 1)
		{
			while(y+1 < n && v2[y+1] == 1) y++;
		}
		return y;
	}
}

int main()
{
	while(cin >> n && n)
	{
		v.clear();
		v2.clear();

		v.resize(n);
		v2.resize(n);

		rep(i,n) cin >> v[i];
		rep(i,n) cin >> v2[i];

		int ans = INF;

		//start 0
		rep(i,101)
		{
			used[i] = false;
			used2[i] = false;
		}

		queue<pair<int,pair<int,int> > > que;
		que.push(make_pair(0,make_pair(0,0)));

		while(que.size())
		{
			int turn = que.front().first;
			pair<int,int> p = que.front().second;
			int y = p.first;
			int type = p.second;

			que.pop();

			int ny = getNext(y,type);
			if(type == 0) 
			{
				if(used[ny]) continue;
				else used[ny] = true;
			}
			else 
			{
				if(used2[ny]) continue;
				else used2[ny] = true;
			}

			if(ny == n-1)
			{
				ans = min(ans,turn);
			}
			
			rep(i,3)
			{
				if(type == 0)
				{
					if(0 <= ny+i && ny+i < n && !used2[ny+i])
					{
						que.push(make_pair(turn+1,make_pair(ny+i,1)));
					}
				}
				else
				{
					if(0 <= ny+i && ny+i < n && !used[ny+i])
					{
						que.push(make_pair(turn+1,make_pair(ny+i,0)));
					}
				}
			}
		}

		//start 1
		rep(i,101)
		{
			used[i] = false;
			used2[i] = false;
		}
		queue<pair<int,pair<int,int> > > que2;
		que2.push(make_pair(0,make_pair(0,1)));
		
		while(que2.size())
		{
			int turn = que2.front().first;
			pair<int,int> p = que2.front().second;
			int y = p.first;
			int type = p.second;

			que2.pop();

			int ny = getNext(y,type);
			if(type == 0) 
			{
				if(used[ny]) continue;
				else used[ny] = true;
			}
			else 
			{
				if(used2[ny]) continue;
				else used2[ny] = true;
			}

			if(ny == n-1)
			{
				ans = min(ans,turn);
			}

			rep(i,3)
			{
				if(type == 0)
				{
					if(0 <= ny+i && ny+i < n && !used2[ny+i])
					{
						que2.push(make_pair(turn+1,make_pair(ny+i,1)));
					}
				}
				else
				{
					if(0 <= ny+i && ny+i < n && !used[ny+i])
					{
						que2.push(make_pair(turn+1,make_pair(ny+i,0)));
					}
				}
			}
		}

		if(ans == INF) cout << "NA" << endl;	
		else cout << ans << endl;

	}
	return 0;
}
