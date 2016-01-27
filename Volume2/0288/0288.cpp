#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

struct Data
{
	int A,E,R;

	Data(int a,int e,int r)
	{
		A = a;
		E = e;
		R = r;
	}
};

int main()
{
	int d,n;
	while(cin >> d >> n)
	{
		if(d == 0 && n == 0) break;


		vector<Data> v;
		rep(i,n)
		{
			int a,e,r;
			cin >> a >> e >> r;

			v.push_back(Data(a,e,r));
		}
		
		queue<pair<pair<int,int>,int> > que;
		que.push(make_pair(make_pair(0,d),0));
		bool flag = true;

		//D exp
		bool memo[105][105];
		memset(memo,0,sizeof(memo));

		while(que.size())
		{
			pair<int,int> p = que.front().first;
			int exp = que.front().second;
			que.pop();

			if(memo[p.second][exp]) continue;
			memo[p.second][exp] = true;

			if(p.second <= 0)
			{
				cout << p.first << endl;
				flag = false;
				break;
			}

			rep(i,n)
			{
				if(v[i].R <= exp)
				{
					que.push(make_pair(make_pair(p.first+1,p.second-v[i].A),exp+v[i].E));
				}
			}
		}

		if(flag) cout << "NA" << endl;
	}
	

	return 0;
}
