#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int a[5] = {0,6000,4000,3000,2000};
	rep(i,4)
	{
		int t,n;
		cin >> t >> n;

		cout << a[t]*n << endl;
	}
	return 0;
}
