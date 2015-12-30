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
	int n, m;
	
	while(cin >> n >> m) {
		if(n == 0 && m == 0) break;

		vector<P> v(m);
		rep(i, m) {
			v[i].first = 0;
			v[i].second = -i;
		}

		rep(i, n) {
			rep(j, m) {
				int x;
				cin >> x;

				if(x == 1) v[j].first++;
			}
		}

		sort(v.begin(), v.end(), greater<P>());
		rep(i, m) {
			cout << -v[i].second + 1;

			if(i == m-1) cout << endl;
			else cout << " ";
		}
	}

	return 0;
}
