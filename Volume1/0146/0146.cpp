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
    cin >> n;

    vector<int> id(n), d(n), v(n);

    rep(i,n) {
        cin >> id[i] >> d[i] >> v[i];
    }

    double dp[1<<15][15];
    vector< vector<int> > path[1<<15];

    rep(i,1<<n) {
        path[i].resize(n);
        rep(j,n) {
            dp[i][j] = INF;
        }
    }

    rep(i,n) {
        dp[1<<i][i] = 0;
        path[1<<i][i].push_back(id[i]);
    }

    rep(k,1<<n) {
        rep(i,n) {
            if(!(k & (1<<i))) continue;
            rep(j,n) {
                if(k & (1 << j)) continue;
                double sum = 0;
                rep(l,v.size()) {
                    if(k & (1<<l)) sum += v[l]*20.0;
                }
                double t = 2000.0 / (70 + sum);
                double cost = abs(d[i]-d[j]) / t;

                if(dp[k|(1<<j)][j] > dp[k][i] + cost) {
                    dp[k|(1<<j)][j] = dp[k][i] + cost;
                    path[k|(1<<j)][j] = path[k][i];
                    path[k|(1<<j)][j].push_back(id[j]);
                }
            }
        }
    }

    double ans = INF;
    int idx;
    rep(i,n) {
        if(ans > dp[(1<<n)-1][i]) {
            ans = dp[(1<<n)-1][i];
            idx = i;
        }
    }

    rep(i,path[(1<<n)-1][idx].size()) {
        cout << path[(1<<n)-1][idx][i];

        if(i == path[(1<<n)-1][idx].size()-1) cout << endl;
        else cout << " ";
    }

    return 0;
}
