#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n;
	while(cin >> n && n)
	{
		string *s = new string[n];
		rep(i,n)
		{
			cin >> s[i];
		}

		vector<int> ans;
		rep(i,n)
		{
			rep(j,n)
			{
				int x = 0;
				while(j <= n-1 && s[i][j] == '.')
				{
					j++;
					x++;
				}

				j -= x;
				
				if(i+x-1 <= n-1)
				{
					bool flag = true;
					REP(k,i,i+x)
					{
						REP(l,j,j+x)
						{
							if(s[k][l] == '*')
							{
								flag = false;
							}
						}
					}
					if(flag) 
					{
						ans.push_back(x);
					}
				}
			}
		}

		sort(ans.begin(),ans.end(),greater<int>());
		cout << ans[0] << endl;
	}
	return 0;
}