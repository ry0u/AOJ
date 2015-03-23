#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	double n;

	while(cin >> n)
	{
		if(n < 0) break;

		int up = (int)n;
		double down = n - up;

		if(0 <= up && up < 256 && down*16 == (int)(down*16))
		{
			int t = (int)(n*16);
			string s;
			rep(i,12)
			{
				if(i < 4)
				{
					if(t & (1 << i)) s += "1";
					else s += "0";
				}
				else
				{
					if(i == 4) s += ".";

					if(t & (1 << i)) s += "1";
					else s+= "0";
				}
			}

			reverse(s.begin(),s.end());
			cout << s << endl;
		}
		else cout << "NA" << endl;
	}
}

