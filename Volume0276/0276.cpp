#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	rep(i,7)
	{
		int a,b;
		cin >> a >> b;

		cout << a-b << endl;
	}
	
	return 0;
}
