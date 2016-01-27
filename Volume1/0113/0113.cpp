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
    int p,q;

    while(cin >> p >> q) {
        vector<int> v,m;
        int last = 0;

        p %= q;
        m.push_back(p);
        p *= 10;

        while(true) {

            v.push_back(p/q);
            last = p%q;

            if(last == 0) break;
            if(find(m.begin(),m.end(),last) != m.end()) break;

            m.push_back(last);
            p = last;
            p *= 10;
        }

        rep(i,v.size()) cout << v[i];
        cout << endl;

        if(last == 0) continue;

        bool flag = false;
        rep(i,v.size()) {
            if(m[i] == last) flag = true;

            if(flag) cout << "^";
            else cout << " ";
        }
        cout << endl;

    }

    return 0;
}
