#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30

using namespace std;

int main()
{
	int n;
	cin >> n;

	rep(i,n)
	{
		int x,y,b,p;
		cin >> x >> y >> b >> p;

		int ret = x*b + y*p;

		b = max(b,5);
		p = max(p,2);

		int res = x*b + y*p;
		res *= 0.8;

		cout << min(ret,res) << endl;
	}
	return 0;
}
