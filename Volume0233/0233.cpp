#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n;
	while(cin >> n && n)
	{
		string s = "";

		while(n != 0)
		{
			int t = n;

			if(n < 0) t *= -1;
			t %= 10;

			if(n < 0) t = (10 - t)%10;

			stringstream ss;
			ss << t;
			s += ss.str();

			n = (n - t)  / -10;
		}

		reverse(s.begin(),s.end());
		cout << s << endl;

	}

	return 0;
}
