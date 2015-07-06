#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main() {
    int n,m;
    cin >> n >> m;
    
    vector<double> L(n),a(n),b(n);
    rep(i,n) cin >> L[i] >> a[i] >> b[i];

    double ans = 0;
    rep(i,1<<n) {
        bitset<20> bit(i);
        if(bit.count() == m) {
            vector<int> res;
            rep(j,20) {
                if(bit[j]) res.push_back(j);
            }

            double sum = 0;
            rep(j,res.size()) {
                REP(k,j+1,res.size()) {
                    int s = res[j];
                    int t = res[k];
                    sum += (L[s]-L[t]) * (L[s]-L[t]);
                    sum += (a[s]-a[t]) * (a[s]-a[t]);
                    sum += (b[s]-b[t]) * (b[s]-b[t]);
                }
            }

            ans = max(ans,sum);
        }
    }
    
    cout << fixed;
    cout.precision(10);
    cout << ans << endl;

    return 0;
}
