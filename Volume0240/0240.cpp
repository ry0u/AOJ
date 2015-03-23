#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

struct bank
{
	int id,r,type;
	double ret;

	bool operator<(const bank &b) const
	{
		return ret < b.ret;
	}
};

int main()
{
	int n;
	while(cin >> n && n)
	{
		int y;
		cin >> y;

		vector<bank> v;
		v.resize(n);
		
		rep(i,n)
		{
			cin >> v[i].id >> v[i].r >> v[i].type;

			if(v[i].type == 1)
			{
				v[i].ret = 10000.0 * (1.0 + double(y) * (v[i].r / 100.0));
			}
			else
			{
				v[i].ret = 10000.0 * pow(1.0 + (v[i].r/100.0),y);
			}
		}

		sort(v.begin(),v.end());

		cout << v[v.size()-1].id << endl;
	}
}
