#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main()
{
	int n;
	while(cin >> n && n)
	{
		vector<int> p,j;
		p.resize(n);
		j.resize(n-1);

		ll ans = 0;
	    ll size = n;
		rep(i,n) 
		{
			cin >> p[i];
			ans += p[i];
		}
		rep(i,n-1) cin >> j[i];

		sort(j.begin(),j.end(),greater<int>());

		rep(i,n-1)
		{
		    ll ret = ans * size;
			ll ret2 = (ans +  j[i]) * (size - 1);

			if(ret2 > ret)
			{
				ans += j[i];
				size--;
			}
			else break;
		}

		cout << ans*size << endl;
	}
}
