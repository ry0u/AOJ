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
		vector<int> a(n),b(n);

		rep(i,n) cin >> a[i];
		rep(i,n) cin >> b[i];

		sort(a.begin(),a.end(),greater<int>());
		sort(b.begin(),b.end());

		bool flag = false;
		rep(i,n-1)
		{
			//revease
			int cnt = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
			cnt = n - cnt;

			if((i+1) - cnt > (i+1)/2)
			{
				cout << i+1 << endl;
				flag = true;
				break;
			}
		}

		if(!flag) cout << "NA" << endl;
	}

	return 0;
}
