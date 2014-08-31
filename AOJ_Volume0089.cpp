#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cstdlib>
#include <algorithm>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int memo3[105][105];
int len[105];
int i;
vector<int> vec;

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

void dfs(int dep,int j,int sum)
{
	sum += memo3[dep][j];
	if(dep == i-1)
	{
		vec.push_back(sum);
		return;
	}

	if(dep < (i-1)/2)
	{
		dfs(dep+1,j,sum);
		dfs(dep+1,j+1,sum);
	}

	else
	{
		if(j == 0)
		{
			dfs(dep+1,0,sum);
		}
		else if(j == len[dep]-1)
		{
			dfs(dep+1,j-1,sum);
		}
		else
		{
			dfs(dep+1,j,sum);
			dfs(dep+1,j-1,sum);
		}
	}
}


int main()
{
	memset(memo3,0,sizeof(memo3));
	string s;
	i = 0;
	int ans = 0;
	bool flag = false;
	while(cin >> s)
	{
		vector<string> _s = split(s,',');
		len[i] = _s.size();
		rep(j,_s.size())
		{
			memo3[i][j] = atoi(_s[j].c_str());
		}
		i++;
	}
	dfs(0,0,0);
	rep(c,vec.size())
	{
		ans = max(ans,vec[c]);
	}
	cout << ans << endl;
	return 0;
}