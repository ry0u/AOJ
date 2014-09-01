#include <iostream>
#include <complex>
#include <vector>
#include <cmath>

#define rep(i,n) for(int i=0;i<n;i++)
#define EPS 1e-6

using namespace std;

typedef complex<double> P;

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		vector<P> p;
		rep(i,4)
		{
			double a,b;
			cin >> a >> b;
			p.push_back(P(a,b));
		}

		P a = p[1] - p[0];
		P b = p[3] - p[2];
		double t = a.real()*b.imag() - a.imag()*b.real();
		if(fabs(t) < EPS)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}