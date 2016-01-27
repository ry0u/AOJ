#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int t;
	while(cin >> t && t)
	{
		int n;
		cin >> n;

		int ret = 0;
		rep(i,n)
		{
			int a,b;
			cin >> a >> b;
			ret += b - a;
		}

		if(t - ret <= 0) cout << "OK" << endl;
		else cout << t - ret << endl;
	}
}
