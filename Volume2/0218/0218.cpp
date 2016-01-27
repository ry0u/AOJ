#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n;
	while(cin >> n && n)
	{

		rep(i,n)
		{
	   		double	pm,pe,pj;
			cin >> pm >> pe >> pj;


			if(pm >= 100 || pe >= 100 || pj >= 100)
			{
				cout << "A" << endl;
			}
			else
			{
				double temp = pm + pe;
				temp /= 2;

		   		double temp2 = pm + pe + pj;
				temp2 /= 3;

				if(temp >= 90)
				{
					cout << "A" << endl;
				}
				else if(temp2 >= 80)
				{
					cout << "A" << endl;
				}
				else if(temp2 >= 70)
				{
					cout << "B" << endl;
				}
				else if(temp2 >= 50 && (pm >= 80 || pe >= 80))
				{
					cout << "B" << endl;
				}
				else cout << "C" << endl;
			}	
		}
	}
}
