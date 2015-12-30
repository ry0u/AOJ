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
	cin >> n >> m;

	vector<int> v(2*n);
	rep(i, 2*n) v[i] = i + 1;

	rep(i, m) {
		int k;
		cin >> k;

		vector<int> a, b;

		if(k == 0) {
			rep(j, n) {
				a.push_back(v[j]);
				a.push_back(v[j+n]);
			}

			v.clear();
			copy(a.begin(),a.end(),back_inserter(v));
		} else {
			rep(j, k) {
				a.push_back(v[j]);
			}

			REP(j, k, 2*n) {
				b.push_back(v[j]);
			}

			v.clear();
			copy(b.begin(),b.end(),back_inserter(v));
			copy(a.begin(),a.end(),back_inserter(v));
		}

	}

	rep(i, 2*n) {
		cout << v[i] << endl;
	}

	return 0;
}
