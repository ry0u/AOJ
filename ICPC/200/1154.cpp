#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main() {
    
    bool T[300005];
    memset(T,0,sizeof(T));

    vector<int> v;
    REP(i,2,300001) {
        if(i%7 == 1 || i%7 == 6) {
            v.push_back(i);
            T[i] = true;
        }
    }

    rep(i,v.size()) {
        int res = v[i];
        int cnt = res*2;
        while(cnt < 300000) {
            T[cnt] = false;
            cnt += res;
        }

    }

    vector<int> res;
    rep(i,300001) {
        if(T[i]) {
            res.push_back(i);
        }
    }

    int n;
    while(cin >> n) {
        if(n == 1) break;
       
        cout << n << ":";
        vector<int> ans;
        rep(i,res.size()) {
            if(n%res[i] == 0){
                ans.push_back(res[i]);
            }
        }
       
        rep(i,ans.size()) {
            cout << " " << ans[i];
        }
        cout << endl;
    }

    return 0;
}
