#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) break;
		
		vector<int> v;
		v.resize(n);

		rep(i,n) cin >> v[i];
		sort(v.begin(),v.end());
		
		int ans = 0;
		for(int i=n-1;i>=0;i -= m)
		{
			if(i-m+1 < 0)
			{
				for(int j=i;j>=0;j--)
				{
					ans += v[j];
				}
			}
			else
			{
				for(int j=i;j>(i-m+1);j--)
				{
					ans += v[j];
				}
			}
		}
		cout << ans << endl;

	}
}
