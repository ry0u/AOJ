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
	while(cin >> s) {
		int a = 0, b = 0;
		rep(i, s.size() - 2) {
			if(s[i] == 'J' && s[i+1] == 'O' && s[i+2] == 'I') a++;
			if(s[i] == 'I' && s[i+1] == 'O' && s[i+2] == 'I') b++;
		}

		cout << a << endl;
		cout << b << endl;
	}
	return 0;
}
