#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int n,j,y;

int main()
{
	cin >> j >> y;
	n = j + y;

	rep(i,1<<n)
	{
		bitset<12> bit(i);

		if(bit.count() == y)
		{
			string s = "";

			rep(j,n)
			{
				if(bit[j] == 0) s += "A";
				else s += "B";
			}

			reverse(s.begin(),s.end());
			int a=0,b=0;
			bool flag = true;

			rep(j,n)
			{
				if(s[j] == 'A') a++;
				else b++;

				if(a <= 3 && b == 5)
				{
					if(j != n-1)
					{
						flag = false;
						break;
					}
				}
				else if(a == 5 && b <= 3)
				{
					if(j != n-1)
					{
						flag = false;
						break;
					}
				}
			}

			if(flag) cout << s << endl;

		}
	}


	return 0;
}
