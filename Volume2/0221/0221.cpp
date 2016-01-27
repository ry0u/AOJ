#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n,m;

	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) break;
		
		string s,temp;
		int p = 0;
		int size = n-1;
		bool can[1010];
		rep(i,1010) can[i] = true;
		
		getline(cin,temp);
		REP(i,1,m+1)
		{
			getline(cin,s);
			
			if(size)
			{
				while(!can[p%n]) p++;

				if(i%15 == 0) temp = "FizzBuzz";
				else if(i%3 == 0) temp = "Fizz";
				else if(i%5 == 0) temp = "Buzz";
				else
				{
					stringstream ss;
					ss << i;
					temp = ss.str();
				}

				if(s != temp)
				{
					can[p%n] = false;
					size--;
				}
				p++;
			}

		}

		bool flag = false;
		rep(i,n)
		{
			if(can[i]) 
			{
				if(flag) cout << " ";

				cout << i+1;
				flag = true;
			}
		}
		cout << endl;
	}
}
