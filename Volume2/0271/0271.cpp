#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007

using namespace std;
typedef long long ll;

int n,r;

ll func(ll x)
{

	if(x <= 1) return 1;

	return (x * func(x-1))%MOD;
}

int main()
{
	while(cin >> n && n)
	{
		cin >> r;

		vector<int> v(n);
		rep(i,n) v[i] = i+1;

		rep(i,r)
		{
			int a,b;
			cin >> a >> b;
			a--;
			b--;

			swap(v[a],v[b]);
		}
		
		vector<pair<int,int> > r;
		rep(i,n)
		{
			if(v[i] != i+1) r.push_back(make_pair(v[i],i+1));
		}
		

		ll cnt = 0;
		ll a = 1, f = 1;

		rep(p,n)
		{
			cout << v[p]-1 << " " << p-1 << endl;
			ll L = max(v[p]-1,p-1);

			ll W = L-p;
			if(W < 0) W = 0;

			rep(i,r.size())
			{
				if(r[i].second <= p) continue;
				if(r[i].second <= L) W--;
				if(r[i].second < v[p]) W++;
			}
				
			cnt += (W * func(p+1)) % MOD;
			cnt %= MOD;
		}
		
		cout << cnt << endl;
		
	}
	return 0;
}
