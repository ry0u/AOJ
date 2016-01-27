#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

vector<vector<int> > v,c;

int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) break;

		v.clear();
		v.resize(n);

		rep(i,n)
		{
			v[i].clear();
			v[i].resize(16);

			rep(j,16) cin >> v[i][j];
		}

		c.clear();
		c.resize(m);

		rep(i,m)
		{
			c[i].clear();
			c[i].resize(16);

			rep(j,16) cin >> c[i][j];
		}

		int ans = 0;
		vector<int> t(16);
		rep(i,16) t[i] = 0;

		rep(i,n)
		{
			rep(j,16) if(v[i][j] == 1) t[j] = v[i][j];

			int ret = 0,num = 0;

			rep(j,m)
			{
				int cnt = 0;
				rep(k,16) if(t[k] == 1 && c[j][k] == 1)  cnt++;

				if(ret < cnt)
				{
					ret = cnt;
					num = j;
				}
			}

			rep(k,16)
			{
				if(t[k] == 1 && c[num][k] == 1) t[k]--;
			}

			ans += ret;
		}

		cout << ans << endl;

	}

	return 0;
}
