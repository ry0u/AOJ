#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 256
#define EPS 1e-8

using namespace std;
typedef long long ll;

int main()
{
    int n;
    while(cin >> n && n) {
        vector<int> I(n);
        rep(i,n) cin >> I[i];
    
        int S = 0,A = 0,C = 0;
        double H = 100000.0;
        
        rep(s,16) {
            rep(a,16) {
                rep(c,16) {
                    double cnt[500];
                    memset(cnt,0,sizeof(cnt));

                    int res = s;
                    rep(i,n) {
                        res = (a * res + c) % MOD;
                        int t = (I[i] + res) % MOD;
                        cnt[t]++;
                    }

                    double ret = 0.0;
                    rep(i,MOD) {
                        if(cnt[i]) {
                            ret -= cnt[i] / n * log(cnt[i] / (double)n);
                        }
                    }

                    // cout << ret << " "<< EPS << " " << ret + EPS << " " << S << endl;

                    if(ret + EPS < H) {
                        H = ret;
                        S = s;
                        A = a;
                        C = c;
                    }
                }
            }
        }

        cout << S << " " << A << " " << C << endl;
    }

    return 0;
}
