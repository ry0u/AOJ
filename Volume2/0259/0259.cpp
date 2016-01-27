#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	string s;
	while(cin >> s)
	{
		if(s == "0000") break;
		
		bool flag = true;
		rep(i,s.size()) if(s[0] != s[i]) flag = false;

		if(flag)
		{
			cout << "NA" << endl;
		}
		else
		{
			int cnt = 0;
			while(true)
			{
				if(s == "6174")
				{
					cout << cnt << endl;
					break;
				}
			
				string temp = s,temp2 = s;
				sort(temp.begin(),temp.end());
				sort(temp2.begin(),temp2.end(),greater<char>());

				int t = atoi(temp.c_str());
				int t2 = atoi(temp2.c_str());

				stringstream ss;
				ss << t2 - t;

				s = "";
				REP(i,ss.str().size(),4) s += "0";

				s += ss.str();
				cnt++;
			}
		}

	}
}
