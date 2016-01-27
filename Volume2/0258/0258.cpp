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
		vector<int> v(n+1);
		rep(i,n+1) cin >> v[i];

		rep(i,n+1)
		{
			bool flag = true;
			vector<int> p;
			rep(j,n+1)
			{
				if(i != j) p.push_back(v[j]);
			}

			int ret = p[1] - p[0]; 
			rep(j,n-1)
			{
				if(p[j+1] - p[j] != ret) flag = false;
			}

			if(flag)
			{
				cout << v[i] << endl;
				break;
			}
		}
	}
}
