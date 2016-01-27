#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int a[300001];
int b[3000001];

int main()
{
	int n,q;
	cin >> n >> q;

	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	map<int,bool> m;
	int t;

	rep(i,n)
	{
		cin >> t;
		m[t] = true;
	}

	t = -1;
	rep(i,300001)
	{
		b[i] = t;

		if(m[i]) t = i;
	}

	rep(i,q)
	{
		int x;
		cin >> x;
		int ans = 0;

		for(int j=0;j<300001;j += x)
		{
			if(b[j] != -1)
			{
				ans = max(ans,b[j]%x);
			}
		}

		cout << ans << endl;
	}
	return 0;
}
