#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int b,r,g,c,s,t;
	while(cin >> b >> r >> g >> c >> s >> t)
	{
		if(b == 0 && r == 0 && g == 0 && c == 0 && s == 0 && t == 0) break;

		int ans = 100;

		ans += b*15 + b*5*(15-2) + r*15 + r*3*(15-2) + g*7 + c*2;
		ans -= (t - b*5 - r*3 - s)*3;

		cout << ans << endl;
	}
}
