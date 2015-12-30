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
	string s;
	cin >> s;

	rep(i, s.size()) {
		cout << char('A' + (s[i] - 'A' - 3 + 26) % 26);
	}
	cout << endl;

	return 0;
}
