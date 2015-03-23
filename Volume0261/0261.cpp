#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

vector<string> split(const string &str, char delim)
{
    vector<string> res;
    size_t current = 0, found;
	while((found = str.find_first_of(delim, current)) != string::npos)
    {
	    res.push_back(string(str, current, found - current));
	    current = found + 1;
    }
    res.push_back(string(str, current, str.size() - current));
    return res;
}

bool isLeapYear(ll y)
{
	if( (y%4 == 0 && y%100 != 0) || (y%400 == 0) ) return true;
	else return false;
}

ll getLeapCount(ll y)
{
	ll ret = y/4;
	ret -= y/100;
	ret += y/400;

	return ret;
}

ll toDate(ll y,ll m,ll d)
{
	ll ret = 0;

	ret += getLeapCount(y-1) * 366;
	ret += (y-1 - getLeapCount(y-1)) * 365;

	REP(i,1,m)
	{
		if(i == 2)
		{
			if(isLeapYear(y)) ret += 29;
			else ret += 28;
		}
		else ret += month[i];
	}

	ret += d;

	return ret;
}

ll toDate(ll b,ll ka,ll t,ll w,ll ki)
{
	ll ret = 0;
	ret += b*20*20*18*20;
	ret += ka * 20*18*20;
	ret += t * 18*20;
	ret += w * 20;
	ret += ki;

	return ret;
}

int main()
{
	string s;
	while(cin >> s)
	{
		if(s == "#") break;
		
		vector<string> _s = split(s,'.');
	
		vector<ll> v;
		v.resize(_s.size());
		rep(i,_s.size()) v[i] = atoll(_s[i].c_str());

		if(_s.size() == 3)
		{
			ll date = (toDate(v[0],v[1],v[2]) - toDate(2012,12,21));
			date %= 13*20*20*18*20;
			
			ll b = 0,ka = 0,t = 0,w = 0,ki = 0;
			

			while(date - 20*20*18*20 >= 0)
			{
				b++;
				date -= 20*20*18*20;
			}

			while(date - 20*18*20 >= 0)
			{
				ka++;
				date -= 20*18*20;
			}

			while(date - 18*20 >= 0)
			{
				t++;
				date -= 18*20;
			}

			while(date - 20 >= 0)
			{
				w++;
				date -= 20;
			}
			
			ki = date;
			
			cout << b << "." << ka << "." << t << "." << w << "." << ki << endl;

		}
		else if(_s.size() == 5)
		{
			ll date = toDate(v[0],v[1],v[2],v[3],v[4]) + toDate(2012,12,21);
			ll y = 0,m = 0,d = 0;

			rep(i,(int)date)
			{
				d++;

				if(m == 2 && isLeapYear(y))
				{
					if(d > month[m] + 1)
					{
						m++;
						d = 1;
					}
				}
				else
				{
					if(d > month[m])
					{
						m++;
						d = 1;
					}
				}

				if(m > 12)
				{
					y++;
					m = 1;
				}
			}
			cout << y << "." << m << "." << d+1 << endl;
		}
	}
}
