#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
#include <cstdlib>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

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

int main()
{
	string t;
	while(true)
	{
		getline(cin,t);
		if(t == "0") break;

		int n = atoi(t.c_str());
		
		vector<pair<int,string> > v;
		vector<string> temp;
		map<string,int> m;
		rep(i,n)
		{
			string s;
			getline(cin,s);
			temp.push_back(s);
		}

		string ret;
		getline(cin,ret);

		rep(i,temp.size())
		{
			vector<string> st = split(temp[i],' ');

			rep(j,st.size())
			{
				if(ret[0] == st[j][0]) m[st[j]]++;
			}
		}

		map<string,int>::iterator ite;
		for(ite = m.begin();ite != m.end();ite++)
		{
			v.push_back(make_pair(-ite->second,ite->first));
		}

		sort(v.begin(),v.end());


		int cnt = 0;

		rep(i,v.size())
		{
			if(cnt == 0 && v[i].second[0] == ret[0])
			{
				cnt++;
				cout << v[i].second;
			}
			else if(0 < cnt && cnt < 5 && v[i].second[0] == ret[0])
			{
				cnt++;
				cout << " " << v[i].second;
			}
		}

		if(cnt == 0) cout << "NA" << endl;
		else cout << endl;
	}
}
