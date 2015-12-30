#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {
    int n,m;
    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;

        vector< vector<int> > v;
        rep(i,3) {
            int x;
            cin >> x;

            vector<int> t(x);
            rep(j,x) cin >> t[j];

            v.push_back(t);
        }

        queue<pair<vector<vector<int> >, int > > que;
        que.push(make_pair(v,0));
        
        set<vector<vector<int > > > st;
        st.insert(v);
        
        int ans = -1;
        
        while(que.size()) {
            vector< vector<int> > f(que.front().first.begin(),que.front().first.end());
            int cnt = que.front().second;
            que.pop();
        
            // cout << "--------------- in queue :: " << cnt << "    size:" << que.size()  << endl;
            // rep(i,3) {
            //     rep(j,f[i].size()) cout << f[i][j] << " ";
            //     cout << endl;
            // }

            if(cnt > m) break;
        
            bool flag = false;
            if(f[0].size() == n) {
                bool ch = true;
                rep(i,f[0].size()) {
                    if(f[0][i] != i+1) ch = false;
                }
        
                if(ch) flag = true;
            }
        
            if(f[2].size() == n) {
                bool ch = true;
                rep(i,f[2].size()) {
                    if(f[2][i] != i+1) ch = false;
                }
        
                if(ch) flag = true;
            }
        
            if(flag) {
                ans = cnt;
                break;
            }
        
            rep(i,3) {
                if(f[i].size() == 0) continue;

                for(int j=-1;j<=1;j++) {
                    int id = i+j;
                    if(id == i || id < 0 || id > 2) continue;

                    vector< vector<int> > t(f.begin(),f.end());

                    if(t[id].size() == 0) {
                        int d = t[i].back();
                        t[i].pop_back();
                        t[id].push_back(d);
                    } else {
                        int d = t[i].back();
                        int top = t[id].back();
                        
                        if(d > top) {
                            t[i].pop_back();
                            t[id].push_back(d);
                        }
                    }

                    if(st.find(t) == st.end()) {
                        st.insert(t);
                        que.push(make_pair(t,cnt+1));
                    }
                }
        
            }
        }

        cout << ans << endl;
        
    }

    return 0;
}
