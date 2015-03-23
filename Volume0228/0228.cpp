#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	map<int,string> m;
	m[0] = "1111110";
	m[1] = "0110000";
	m[2] = "1101101";
	m[3] = "1111001";
	m[4] = "0110011";
	m[5] = "1011011";
	m[6] = "1011111";
	m[7] = "1110010";
	m[8] = "1111111";
	m[9] = "1111011";

	int n;
	while(cin >> n)
	{
		if(n == -1) break;

		string now = "0000000";
		bool flag[7];
		rep(i,7) flag[i] = false;

		rep(i,n)
		{
			int k;
			cin >> k;
		
			string ans = "0000000";
			rep(j,7)
			{
				if(now[j] != m[k][j])
				{
					ans[j] = '1';
				}
			}
			now = m[k];

			reverse(ans.begin(),ans.end());
			cout << ans << endl;
		}
	}
}
