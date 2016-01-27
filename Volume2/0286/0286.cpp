#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

ll c[10005];

int main()
{
	int n,m;
	cin >> n >> m;

	vector<pair<pair<int,int>,int> > a;
	while(true)
	{
		int s,t,e;
		cin >> s >> t >> e;

		if(s == 0 && t == 0 && e == 0) break;

		s--;
		t--;

		a.push_back(make_pair(make_pair(s,t),e));
	}

	int l;
	cin >> l;
	rep(q,l)
	{
		memset(c,0,sizeof(c));
		vector<int> b(m);
		rep(i,m) cin >> b[i];
			
		rep(i,a.size())
		{
			int s = a[i].first.first;
			int t = a[i].first.second;
			int e = a[i].second;

			c[s] += b[t] * e;
		}

		rep(i,n)
		{
			cout << c[i];
			if(i == n-1) cout << endl;
			else cout << " ";
		}
	}	

	return 0;
}
