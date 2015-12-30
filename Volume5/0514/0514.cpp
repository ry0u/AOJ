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
	int a, b, c, n;

	while(cin >> a >> b >> c) {
		if(a == 0 && b == 0 && c == 0) break;

		cin >> n;

		vector<int> A(n), B(n), C(n), D(n);
		rep(i, n) cin >> A[i] >> B[i] >> C[i] >> D[i];

		bool used[500];
		memset(used, 0, sizeof(used));

		rep(i, n) {
			if(D[i] == 1) {
				used[A[i]] = true;
				used[B[i]] = true;
				used[C[i]] = true;
			}
		}

		set<int> st;
		rep(i, n) {
			if(D[i] == 0) {
				if(used[A[i]] && used[B[i]]) {
					st.insert(C[i]);
				} else if(used[A[i]] && used[C[i]]) {
					st.insert(B[i]);
				} else if(used[B[i]] && used[C[i]]) {
					st.insert(A[i]);
				}
			}
		}

		REP(i, 1, a + b + c + 1) {
			if(used[i]) cout << 1 << endl;
			else if(st.find(i) != st.end()) cout << 0 << endl;
			else cout << 2 << endl;
		}
	}

	return 0;
}
