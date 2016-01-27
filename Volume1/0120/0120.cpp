#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair
#define EPS 1e-8
#define equals(a,b) fabs((a) - (b)) < EPS

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

vector<string> split(const string &str, char delim) {
    vector<string> res;
    size_t current = 0, found;
    while((found = str.find_first_of(delim, current)) != string::npos) {
        res.push_back(string(str, current, found - current));
        current = found + 1;
    }
    res.push_back(string(str, current, str.size() - current));
    return res;
}

int stoi(string s) {
    int ret;
    stringstream ss;
    ss << s;
    ss >> ret;
    return ret;
}

double dp[1<<12][12];

int main() {
    string s;
    while(getline(cin,s)) {
        vector<string> t = split(s,' ');
        int len = stoi(t[0]);
        vector<int> v;
        REP(i,1,t.size()) {
            v.push_back(stoi(t[i]));
        }
        int n = v.size();

        rep(i,1<<n) {
            rep(j,n) dp[i][j] = INF;
        }

        rep(i,n) {
            dp[1<<i][i] = v[i];
        }

        rep(k,(1<<n)) {
            rep(i,n) {
                rep(j,n) {
                    if(k & (1<<j)) continue;
                    double r = (v[i]+v[j]) * (v[i]+v[j]) - (v[i]-v[j])*(v[i]-v[j]);
                    dp[k|(1<<j)][j] = min(dp[k|(1<<j)][j],dp[k][i] + sqrt(r));
                }
            }
        }

        double res = INF;
        rep(i,n) {
            res = min(res,dp[(1<<n)-1][i] + v[i]);
        }

        if(res <= len) cout << "OK" << endl;
        else cout << "NA" << endl;
    }
    return 0;
}
