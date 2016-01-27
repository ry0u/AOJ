#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int prime[10000001];
int num[1000001];

void CreatePrime()
{
	rep(i,1000001) prime[i] = 1;

	prime[0] = prime[1] = 0;

	REP(i,2,sqrt(1000001)+1)
	{
		for(int j=0;i*(j+2)<1000001;j++)
		{
			prime[i*(j+2)] = 0;
		}
	}
	
	memset(num,0,sizeof(num));
	int cnt = 1;
	REP(i,1,1000001)
	{
		if(prime[i]) 
		{
			num[i] = cnt;	
			cnt++;
		}
		else
		{
			num[i] = num[i-1];
		}
	}
}

int main()
{
	CreatePrime();
	
	int n;
	while(cin >> n && n)
	{
		int ans = -n;

		rep(i,n)
		{
			int p,m;
			cin >> p >> m;

			int s = p-m;
			int e = p+m;

			if(s < 0) s = 0;
			if(e > 1000000) e = 1000000;
			
			int count = num[e] - num[s];
			if(prime[s]) count++;

			if(count < 0) ans--;
			else ans += count;
		}
		
		if(ans < 0) cout << 0 << endl;
		else cout << ans << endl;
	}
	return 0;
}
