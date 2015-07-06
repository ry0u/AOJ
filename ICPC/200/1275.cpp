#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main() {
    int n,k,m;
    while(cin >> n >> k >> m) {
        if(n == 0 && k == 0 && m == 0) break;

        bool used[10005];
        memset(used,0,sizeof(used));


        vector<int> v;
        rep(i,n) {
            v.push_back(i);
        }
        
        int id = m-1;
        v.erase(v.begin()+id);
        used[id] = true;

        while(v.size() != 1) {
            id += k-1;
            id %= v.size();

            used[v[id]] = true;
            v.erase(v.begin() + id);
        }

        cout << v[0]+1 << endl;
    }
    return 0;
}
