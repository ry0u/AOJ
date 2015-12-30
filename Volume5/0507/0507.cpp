#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
vector< vector<int> > ans;

void dfs(vector<int> v, int t, int sum) {
	if(sum == n) {
		ans.push_back(v);
		return;
	}

	for(int i = t; i >= 1; i--) {
		if(sum + i <= n) {
			vector<int> ret(v.begin(), v.end());
			ret.push_back(i);
			dfs(ret, i, sum + i);
		}
	}

	return;
}

int main() {
	while(cin >> n && n) {
		ans.clear();

		vector<int> v;
		dfs(v, n, 0);

		rep(i, ans.size()) {
			vector<int> t = ans[i];

			rep(j, t.size()) {
				cout << t[j];

				if(j == t.size()-1) cout << endl;
				else cout << " ";
			}
		}
	}

	return 0;
}
