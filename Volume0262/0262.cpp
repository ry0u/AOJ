#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int n,m;
int start,end;
vector<int> v,p;
vector<bool> flag,used;
bool ans;

void init(int now)
{
	rep(i,end+1)
	{
		int next = i + v[i];
		if(now == next || (now == end && now < next))
		{
			REP(j,1,m+1)
			{
				if(0 <= i-j && !flag[i-j])
				{
					flag[i-j] = true;
					init(i-j);
				}
			}
		}
	}

	return;
}

void dfs(int now)
{
	if(!flag[now]) 
	{
		ans = false;
	}

	REP(j,1,m+1)
	{
		if(now + j <= end)
		{
			int next = now + j + v[now + j];
			if(next < 0) next = 0;
			if(next > end) next = end;

			if(used[next]) continue;
			used[next] = true;
			dfs(next);
		}
	}

	return;
}

int main()
{
	while(cin >> m && m)
	{
		p.clear();
		p.resize(m);
		rep(i,m) p[i] = i+1;

		cin >> n;

		v.clear();
		v.resize(n+2);
		
		v[0] = 0;
		start = 0;

		REP(i,1,n+1) cin >> v[i];

		v[n+1] = 0;
		end = n+1;
	
		ans = true;

		used.clear();
		used.resize(n+2);
		rep(i,n+2) used[i] = false;
		used[0] = true;

		flag.clear();
		flag.resize(n+2);
		rep(i,n+2) flag[i] = false;

		flag[end] = true;
		init(end);
		dfs(0);

		if(ans) cout << "OK" << endl;
		else cout << "NG" << endl;
	}

	return 0;
}
