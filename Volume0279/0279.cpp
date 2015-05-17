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
		vector<int> v(n);
		rep(i,n) cin >> v[i];

		bool flag = false;
		rep(i,n)
		{
			if(v[i] >= 2)
			{
				flag = true;
				break;
			}
		}

		if(flag)
		{
			int cnt=0;
			rep(i,n)
			{
				if(v[i] == 0) continue;
				cnt++;
			}

			cout << cnt+1 << endl;
		}
		else cout << "NA" << endl;
	}

	return 0;
}
