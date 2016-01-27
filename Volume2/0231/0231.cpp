#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

struct Time
{
	int t,cost;

	Time(int _t,int _cost)
	{
		t = _t;
		cost = _cost;
	}

	bool operator<(const Time &ti) const
	{
		return t < ti.t;
	}
};

int main()
{
	int n;
	while(cin >> n && n)
	{
		map<int,int> ma;

		rep(i,n)
		{
			int m,a,b;
			cin >> m >> a >> b;

			ma[a] += m;
			ma[b] -= m;
		}

		vector<Time> v;
		map<int,int>::iterator ite;
		for(ite = ma.begin();ite != ma.end();ite++)
		{
			v.push_back(Time(ite->first,ite->second));	
		}

		sort(v.begin(),v.end());
		vector<int> res;
		res.resize(v.size());
		
		int temp = 0;

		rep(i,v.size())
		{
			temp += v[i].cost;
			res[i] = temp;
		}

		bool flag = true;
		rep(i,res.size())
		{
			if(res[i] > 150) flag = false;
		}


		if(flag) cout << "OK" << endl;
		else cout << "NG" << endl;

	}

	return 0;
}
