#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset> 
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

vector<bitset<16> > v,c;
int memo[31][1<<16];
int n,m;

int dfs(bitset<16> t,int i)
{
	if(i == n) return 0;

	t |= v[i];
	if(memo[i][t.to_ulong()] != -1) return memo[i][t.to_ulong()];

	int ret = 0;
	rep(j,m)
	{
		bitset<16> bit = t & c[j];
		int temp = t.to_ulong() - bit.to_ulong();

		ret = max(ret,dfs(bitset<16>(temp),i+1) + (int)bit.count());
	}

	return memo[i][t.to_ulong()] = ret;
};

int main()
{
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) break;

		v.clear();
		c.clear();
		memset(memo,-1,sizeof(memo));
		int temp;

		rep(i,n)
		{
			double t = pow(2.0,15);
			int ret = 0;
			rep(j,16)
			{
				cin >> temp;
				ret += temp * t;
				t /= 2;
			}

			bitset<16> bit(ret);
			v.push_back(bit);
		}

		rep(i,m)
		{
			double t = pow(2.0,15);
			int ret = 0;
			rep(j,16) 
			{
				cin >> temp;
				ret += temp*t;
				t /= 2;
			}
			
			bitset<16> bit(ret);
			c.push_back(bit);
		}

		cout << dfs(bitset<16>(0),0) << endl;
	}

	return 0;
}
