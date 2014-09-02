#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define rep(i,n) for(int i=0;i<n;i++)
#define EPS 1e-6
using namespace std;

int main()
{
	vector<int> v;
	int a[3];
	while(true)
	{
		cin >> a[0] >> a[1] >> a[2];
		if(a[0] == 0 && a[1] == 0 && a[2] == 0)
		{
			break;
		}

		rep(i,3)
		{
			v.push_back(a[i]);
		}

		sort(v.begin(),v.end());
		int dis = v[0]*v[0] + v[1]*v[1];
		cout << dis << endl;

		int n;
		cin >> n;

		while(n--)
		{
			int r;
			cin >> r;

			r *= 2;

			if(dis < r*r)
			{
				cout << "OK" << endl;
			}
			else
			{
				cout << "NA" << endl;
			}

		}
	}
	return 0;
}