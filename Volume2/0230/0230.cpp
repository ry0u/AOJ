#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30

using namespace std;

int main()
{
	int n;
	while(cin >> n && n)
	{
		vector<int> v,v2;
		v.resize(n);
		v2.resize(n);

		rep(i,n) cin >> v[i];
		rep(i,n) cin >> v2[i];

		int now = 0;
		int ans = INF;
		bool used[100],used2[100];
		rep(i,100)
		{
			used[i] = false;
			used2[i] = false;
		}

		queue<pair<int,pair<int,int> > > que;
		que.push(make_pair(1,make_pair(0,0)));

		while(que.size())
		{
			int type = que.front().first;
			pair<int,int> p = que.front().second;
			
			cout << "n:" << n << endl;;
			cout << type << " " << p.first << " " << p.second << endl;
			que.pop();

			if(p.first > n-1)
			{
				cout << "koko" << endl; 
			}
			else if(p.first == n-1)
			{
				ans = min(ans,p.second);
			}
			else
			{
				if(type == 1)
				{
					int y = p.first;
					if(v2[y+2] == 1)
					{
						while(y+2 < n && v2[y+2] == 1) y++;

						if(!used2[y+2])
						{
							que.push(make_pair(2,make_pair(y+2,p.second+1)));
							used2[y+2] = true;
						}
					}
					else if(v2[y+2] == 2)
					{
						while(y+2 >= 0 && v2[y+2] == 2) y--;
						
						if(!used2[y+2])
						{
							que.push(make_pair(2,make_pair(y+2,p.second+1)));
							used2[y+2] = true;
						}
					}
					else 
					{
						if(!used2[y+2])
						{
							que.push(make_pair(2,make_pair(y+2,p.second+1)));
							used2[y+2] = true;
						}
					}


					y = p.first;
					if(v2[y+1] == 1)
					{
						while(y+1 < n && v2[y+1] == 1) y++;
						if(!used2[y+1])
						{
							que.push(make_pair(2,make_pair(y+1,p.second+1)));
							used2[y+1] = true;
						}
					}
					else if(v2[y+1] == 2)
					{
						while(y+1 >= 0 && v2[y+1] == 2) y--;
						if(!used2[y+1])
						{
							que.push(make_pair(2,make_pair(y+1,p.second+1)));
							used2[y+1] = true;
						}
					}
					else 
					{
						if(!used2[y+1])
						{
							que.push(make_pair(2,make_pair(y+1,p.second+1)));
							used2[y+1] = true;
						}
					}

					y = p.first;
					if(v2[y] == 1)
					{
						while(y < n && v2[y] == 1) y++;
						if(!used2[y])
						{
							que.push(make_pair(2,make_pair(y,p.second+1)));
							used2[y] = true;
						}
					}
					else if(v2[y] == 2)
					{
						while(y < n && v2[y] == 2) y--;
						if(!used2[y])
						{
							que.push(make_pair(2,make_pair(y,p.second+1)));
							used2[y] = true;
						}
					}
					else 
					{
						if(!used2[y])
						{
							que.push(make_pair(2,make_pair(y,p.second+1)));
							used2[y] = true;
						}
					}
				}
				else
				{
					int y = p.first;
					if(v[y+2] == 1)
					{
						while(y+2 < n && v[y+2] == 1) y++;
						if(!used[y+2])
						{
							que.push(make_pair(1,make_pair(y+2,p.second+1)));
							used[y+2] = true;
						}
					}
					else if(v[y+2] == 2)
					{
						while(y+2 >= 0 && v[y+2] == 2) y--;
						if(!used[y+2])
						{
							que.push(make_pair(1,make_pair(y+2,p.second+1)));
							used[y+2] = true;
						}
					}
					else 
					{
						if(!used[y+2])
						{
							que.push(make_pair(1,make_pair(y+2,p.second+1)));
							used[y+2] = true;
						}
					}

					y = p.first;
					if(v[y+1] == 1)
					{
						while(y+1 < n && v[y+1] == 1) y++;
						if(!used[y+1])
						{
							que.push(make_pair(1,make_pair(y+1,p.second+1)));
							used[y+1] = true;
						}
					}
					else if(v[y+1] == 2)
					{
						while(y+1 >= 0 && v[y+1] == 2) y--;
						if(!used[y+1])
						{
							que.push(make_pair(1,make_pair(y+1,p.second+1)));
							used[y+1] = true;
						}
					}
					else 
					{
						if(!used[y+1])
						{
							que.push(make_pair(1,make_pair(y+1,p.second+1)));
							used[y+1] = true;
						}
					}

					y = p.first;
					if(v[y] == 1)
					{
						while(y < n && v[y] == 1) y++;
						if(!used[y])
						{
							que.push(make_pair(1,make_pair(y,p.second+1)));
							used[y] = true;
						}
					}
					else if(v[y] == 2)
					{
						while(y >= n && v[y] == 2) y--;
						if(!used[y])
						{
							que.push(make_pair(1,make_pair(y,p.second+1)));
							used[y] = true;
						}
					}
					else 
					{
						if(!used[y])
						{
							que.push(make_pair(1,make_pair(y,p.second+1)));
							used[y] = true;
						}
					}
				}
			}
		}

		if(ans == INF) cout << "NA" << endl;
		else cout << ans << endl;
	}
}
