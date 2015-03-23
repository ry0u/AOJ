#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

bool prime[10000001];
void Eratosthenes(int n)
{
	rep(i,n) prime[i] = true;
	prime[1] = false;

	REP(i,2,(int)sqrt(n))
	{
		if(prime[i])
		{
			for(int j=0;i*(j+2)<n;j++)
			{
				prime[i*(j+2)] = 0;
			}
		}
	}
} 

int main()
{
	Eratosthenes(10000001);
	
	int n;
	while(cin >> n && n)
	{
		ll ans = 0;
		for(int i=n;i>=0;i--)
		{
			if(prime[i] && prime[i-2] && prime[i-6] && prime[i-8])
			{
				ans = i;
				break;
			}
		}

		cout << ans << endl;
	}
}
