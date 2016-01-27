#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n;
	while(cin >> n && n)
	{
		int ans = 0,res = 0;
		rep(i,n)
		{
			int a,b,c;
			cin >> a >> b >> c;
			
			if(i == 0)
			{
				ans = a;
				res = b + c;
			}

			if(res < b + c)
			{
				ans = a;
				res = b + c;
			}
		}

		cout << ans << " " << res << endl;
	}
}
