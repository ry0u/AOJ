#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

string s;
char end;

void func(char c,int turn)
{
	if(turn == s.size())
	{
		end = c;
		return;
	}

	if(c == 'A')
	{
		if(s[turn] == '0') func('X',turn+1);
		else if(s[turn] == '1') func('Y',turn+1);
		else
		{
			end = 'N';
			return;
		}
	}
	if(c == 'X')
	{
		if(s[turn] == '1') func('Z',turn+1);
		else
		{
			end = 'N';
			return;
		}
	}
	if(c == 'Y')
	{
		if(s[turn] == '0') func('X',turn+1);
		else
		{
			end = 'N';
			return;
		}
	}
	if(c == 'Z')
	{
		if(s[turn] == '0') func('W',turn+1);
		else if(s[turn] == '1') func('B',turn+1);
		else 
		{
			end = 'N';
			return;
		}
	}
	if(c == 'W')
	{
		if(s[turn] == '0') func('B',turn+1);
		else if(s[turn] == '1') func('Y',turn+1);
		else
		{
			end = 'N';
			return;
		}
	}
	if(c == 'B')
	{
		if(s[turn] == '0') func('Y',turn+1);
		else if(s[turn] == '1') func('X',turn+1);
		else
		{
			end = 'N';
			return;
		}
	}
}

int main()
{
	while(cin >> s)
	{
		if(s == "#") break;

		func('A',0);

		if(end == 'B') cout << "Yes" << endl;
		else cout << "No" << endl;

	}

	return 0;
}
