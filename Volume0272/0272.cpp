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
		sort(b.begin(),b.end(),greater<int>());

		vector<int> cnt(n,0);
		rep(i,n)
		{
			if(a[i] > b[i]) cnt[i]++;
		}

		REP(i,1,n)
		{
			cnt[i] += cnt[i-1];
		}
	
		bool flag = false;
		rep(i,n)
		{
			int t = (i+1)/2 + 1;

			if(cnt[i] >= t)
			{
				flag = true;
				cout << i+1 << endl;
				break;
			}
		}

		if(!flag) cout << "NA" << endl; 
	}

	return 0;
}
