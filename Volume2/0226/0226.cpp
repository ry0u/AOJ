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
	string s,s2;
	
	while(cin >> s >> s2)
	{
		if(s == "0" && s2 == "0") break;

		map<char,int> m;
		bool flag[4];
		int hit = 0,b = 0;
		rep(i,4)
		{
			if(s[i] == s2[i]) 
			{
				hit++;
				flag[i] = true;
			}
			else 
			{
				m[s[i]]++;
				flag[i] = false;
			}
		}

		rep(i,4)
		{
			if(!flag[i] && m[s2[i]] > 0)
			{
				b++;
			}
		}

		cout <<  hit << " " << b << endl;

	}
}
