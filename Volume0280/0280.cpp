#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n;
	while(cin >> n && n)
	{
		string s;
		cin >> s;

		vector<int> v(n,0);
		int sum = 0;

		rep(i,100)
		{
			int id = i%n;
			if(s[i] == 'M')
			{
				v[id]++;
			}
			else if(s[i] == 'S')
			{
				sum += v[id]+1;
				v[id] = 0;
			}
			else if(s[i] == 'L')
			{
				v[id] += sum+1;
				sum = 0;
			}
		}

		sort(v.begin(),v.end());
		rep(i,n) cout << v[i] << " ";
		cout << sum << endl;
	}

	return 0;
}
