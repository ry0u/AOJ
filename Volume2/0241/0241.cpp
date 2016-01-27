#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main()
{
	int n;
	while(cin >> n && n)
	{
		rep(i,n)
		{
			int a[4],b[4];
			rep(j,4) cin >> a[j];
			rep(j,4) cin >> b[j];

			ll x = a[0]*b[0] - a[1]*b[1] - a[2]*b[2] - a[3]*b[3];
			ll y = a[0]*b[1] + a[1]*b[0] + a[2]*b[3] - a[3]*b[2];
			ll z = a[0]*b[2] - a[1]*b[3] + a[2]*b[0] + a[3]*b[1];
			ll w = a[0]*b[3] + a[1]*b[2] - a[2]*b[1] + a[3]*b[0];

			cout << x << " " << y << " " << z << " " << w << endl;
		}
	}
}
