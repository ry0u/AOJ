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

int p[1000005];

//max
struct Seg
{
	int n;
	vector<int> dat,id;

	Seg(int n_)
	{
		n = 1;
		while(n < n_) n *= 2;

		dat.resize(2*n-1);
		id.resize(2*n-1);
		rep(i,2*n-1)
		{
			dat[i] = -INF;
			id[i] = -1;
		}

		rep(i,n) update(i,INF);
	}

	void update(int k,int a)
	{
		k += n-1;
		dat[k] += a;
		id[k] = k-n+1;

		while(k > 0)
		{
			k = (k-1) / 2;
			if(dat[k*2+1] == dat[k*2+2])
			{
				dat[k] = dat[k*2+1];
				id[k] = id[k*2+1];
			}
			else
			{
				if(dat[k*2+1] > dat[k*2+2])
				{
					dat[k] = dat[k*2+1];
					id[k] = id[k*2+1];
				}
				else
				{
					dat[k] = dat[k*2+2];
					id[k] = id[k*2+2];
				}
			}
		}
	}
};


int main()
{
	int n,r,l;
	cin >> n >> r >> l;

	//time id,point
	map<int,vector<pair<int,int> > > m;
	rep(i,r)
	{
		int d,t,x;
		cin >> d >> t >> x;

		m[t].push_back(make_pair(d,x));
	}

	vector<int> v(n);
	memset(p,0,sizeof(p));
	Seg seg(n);

	int top_id = 0,pre_time = 0;
	map<int,vector<pair<int,int> > >::iterator ite;
	for(ite = m.begin(); ite != m.end(); ite++)
	{
		int d,t,x;
		t = ite->first;

		v[top_id] = t - pre_time;
		pre_time = t;

		// rep(i,m[t].size())
		// {
		// 	d = m[t][i].first;
		// 	x = m[t][i].second;
		//
		// 	seg.update(d-1,x);
		// 	top_id = seg.id[0];
		// }
	}

	v[top_id] += l - pre_time;

	int res = 0;
	rep(i,n)
	{
		res = max(res,v[i]);
	}

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
