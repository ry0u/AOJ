#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>


#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define mp make_pair

using namespace std;

string shuffle(string merry)
{
	char temp[8];
	rep(i,8) temp[i] = merry[i];
	merry[0] = temp[7];
	REP(i,1,8) merry[i] = temp[i-1];
	return merry;
}


int main()
{
	string merry = "41412121";
	int a[8];
	
	while(cin >> a[0])
	{
		REP(i,1,8)
		{
			cin >> a[i];
		}

		
		vector<int> counter;
		int max_count = 0;
		rep(i,8)
		{
			int count = 0;
			rep(j,8)
			{
				if(merry[j] - '0' >= a[j])
				{
					count += a[j];
				}
				else
				{
					count += merry[j] - '0';
				}
			}

			counter.push_back(count);
			max_count = max(max_count,count);

			merry = shuffle(merry);
		}

		vector<string> ans;
		rep(i,8)
		{
			if(counter[i] == max_count)
			{
				rep(j,i)
				{
					merry = shuffle(merry);
				}
				ans.push_back(merry);
				merry = "41412121";
			}
		}

		string min_ans = ans[0];
		rep(i,ans.size())
		{
			min_ans = min(min_ans,ans[i]);
		}

		
		rep(i,8)
		{
			if(i == 7)
			{
				cout << min_ans[i] << endl;;
			}
			else
			{
				cout << min_ans[i] << " ";
			}
		}
	}
	return 0;
}