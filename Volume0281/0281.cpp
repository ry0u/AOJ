#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int ans;

void dfs(vector<int> x,int cnt)
{
	if(x[0] >= 1 && x[1] >= 1 && x[2] >= 1)
	{
		x[0]--;
		x[1]--;
		x[2]--;

		dfs(x,cnt+1);
	}
	else if(x[0] >= 2 && x[1] >= 1)
	{
		x[0] -= 2;
		x[1]--;

		dfs(x,cnt+1);
	}
	else if(x[0] >= 3)
	{
		x[0] -= 3;
		dfs(x,cnt+1);
	}

	ans = max(ans,cnt);
}

int main()
{
	int n;
	cin >> n;

	rep(i,n)
	{
		vector<int> v(3);
		rep(i,3) cin >> v[i];

		ans = 0;
		dfs(v,0);

		cout << ans << endl;
	}
	return 0;
}
