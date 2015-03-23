#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int ans = 0;

	rep(i,10)
	{
		int temp;
		cin >> temp;

		ans += temp;
	}

	cout << ans << endl;
}
