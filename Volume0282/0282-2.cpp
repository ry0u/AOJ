#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30

using namespace std;
typedef long long ll;

//max
struct SegTree
{
	int n;
	vector<ll> dat;
	vector<int> id;

	SegTree(int n_)
	{
		n = 1;
		while(n < n_) n *= 2;

		dat.resize(n*4);
		id.resize(n*4);
		rep(i,n*4) dat[i] = -INF;
		rep(i,n_) update(i,INF);
	}

	void update(int k,int a)
	{
		int i = k+n-1;
		dat[i] += a;
		id[i] = k;

		while(i > 0)
		{
			i = (i-1) / 2;
			if(dat[i*2+1] >= dat[i*2+2])
			{
				dat[i] = dat[i*2+1];
				id[i] = id[i*2+1];
			}
			else
			{
				dat[i] = dat[i*2+2];
				id[i] = id[i*2+2];
			}
		}
	}
};


int main()
{
	int n,r,l;
	cin >> n >> r >> l;


	vector<int> v(n,0);
	SegTree st(n);

	int top_id = st.id[0],pre_time = 0;
	rep(i,r)
	{
		int d,t,x;
		cin >> d >> t >> x;

		v[top_id] = t - pre_time;
		pre_time = t;

		st.update(d-1,x);

		top_id = st.id[0];
	}

	v[top_id] += l - pre_time;

	int res = 0;
	rep(i,n) res = max(res,v[i]);
	rep(i,n)
	{
		if(res == v[i])
		{
			cout << i+1 << endl;
			break;
		}
	}

	return 0;
}
