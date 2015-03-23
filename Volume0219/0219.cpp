#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30

using namespace std;

int main()
{
	int n;
	while(cin >> n && n)
	{
		map<int,int> m;
		rep(i,n)
		{
			int temp;
			cin >> temp;

			m[temp]++;
		}
		
		rep(i,10)
		{
			if(m[i] == 0) cout << "-" << endl;
			else
			{
				rep(j,m[i]) cout << "*";
				cout << endl;
			}
		}
	}
}
