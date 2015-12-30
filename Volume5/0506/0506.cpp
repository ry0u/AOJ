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
	int n;

	while(cin >> n && n) {
		string s;
		cin >> s;

		rep(k, n) {
			stringstream ss;
			int len = 0;
			rep(i, s.size()) {
				len = 1;
				REP(j, i + 1, s.size()) {
					if(s[i] == s[j]) {
						len++;
						i++;
						continue;
					} else break;
				}
				ss << len;
				ss << s[i];
			}
			s = ss.str();
		}

		cout << s << endl;

	}

	return 0;
}
