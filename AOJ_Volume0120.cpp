#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back

using namespace std;

vector<string> split(string &str,char delim)
{
	vector<string> res;
	size_t current = 0,found;
	while((found = str.find_first_of(delim,current)) != string::npos)
	{
		res.push_back(string(str,current,found  - current));
		current = found + 1;
	}
	res.push_back(string(str,current,str.size() - current));
	return res;
}

int main()
{
	string s;
	while(getline(cin,s))
	{
		vector<string> _s = split(s,' ');
		vector<int> a;
		int n = 0;

		rep(i,_s.size())
		{
			a.pb(atoi(_s[i].c_str()));
			n++;
		}

		int len = a[0];
		a.erase(a.begin());

		double min_len = 10000000;
		do
		{
			double sum = 0;
			sum += a[0];

			rep(i,n-2)
			{
				double temp = (a[i]+a[i+1])*(a[i]+a[i+1]) - (a[i]-a[i+1])*(a[i]-a[i+1]);
				temp = sqrt(abs(temp));
				sum += temp;
			}

			sum += a[n-2];

			min_len = min(min_len,sum);
		}while(next_permutation(a.begin(),a.end()));

		if(min_len <= len) cout << "OK" << endl;
		else cout << "NA" << endl;

		cout << min_len << endl;
	}
	
	return 0;
}