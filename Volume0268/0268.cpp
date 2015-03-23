#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <sstream>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;

	rep(i,n)
	{
		string s;
		cin >> s;

		string ret = "";

		rep(j,8)
		{
			int temp;
			if('0' <= s[j] && s[j] <= '9') temp = s[j] - '0';
			else temp = (s[j] - 'a') + 10;

			bitset<4> bit(temp);
			ret += bit.to_string();
		}
		
		reverse(ret.begin(),ret.end());

		double ans = 0;
		double t = 1.0;
		int k = 1;

		for(int j=6;j>=0;j--)
		{
			t *= 0.5;
			ans += t*(ret[j] - '0');

			if(ret[j] - '0' == '1') k = 7-j;
		}

		ll t2 = 1,ans2 = 0;

		REP(j,7,31)
		{
			ans2 += t2*(ret[j] - '0');
			t2 *= 2;
		}

		if(ret[31] == '1')
		{
			cout << "-";
		}
		cout << ans2;

		if(ans == 0)
		{
			cout << ".0" << endl;
		}
		else
		{
			stringstream ss;
			ss.precision(8);
			ss << ans;
			string ret2 = ss.str();

			REP(j,1,ret2.size())
			{
				cout << ret2[j];
			}
			cout << endl;
		}
	}
	return 0;
}
