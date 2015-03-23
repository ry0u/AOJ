#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

struct Data
{
	int id,p,q,r,c;
};

int main()
{
	int n;
	while(cin >> n && n)
	{
		vector<Data> v;
		v.resize(n);

		rep(i,n)
		{
			int id,p,q,r;
			cin >> id >> p >> q >> r;
			v[i].id = id;
			v[i].p = p;
			v[i].q = q;
			v[i].r = r;
			v[i].c = p*4 + q*9 + r*4;
		}

		int P,Q,R,C;
		cin >> P >> Q >> R >> C;

		bool flag = true;
		rep(i,n)
		{
			if(v[i].p <= P && v[i].q <= Q && v[i].r <= R && v[i].c <= C)
			{
				flag = false;
				cout << v[i].id << endl;
			}
		}

		if(flag) cout << "NA" << endl;
	}
}
