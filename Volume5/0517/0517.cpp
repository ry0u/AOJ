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

int main() {
	int n, k;
	while(cin >> n >> k) {
		if(n == 0 && k == 0) break;

		vector<int> v;
		bool flag = false;
		rep(i, k) {
			int x;
			cin >> x;

			if(x == 0) {
				flag = true;
			} else {
				v.push_back(x);
			}
		}

		sort(v.begin(), v.end());

		vector<P> p;
		int left = -1, right = -1;
		rep(i, v.size()) {
			left = v[i];
			right = v[i];
			REP(j, i+1, v.size()) {
				if(right + 1 == v[j]) {
					right = v[j];
					i++;
				} else break;
			}

			p.push_back(mp(left, right));
		}

		int ans = 0;
		rep(i, p.size()) {
			ans = max(ans, p[i].second - p[i].first + 1);
		}

		if(flag) {
			REP(i, 1, p.size()) {
				if(p[i].first - p[i-1].second == 2) {
					ans = max(ans, p[i].second - p[i-1].first + 1);
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}
