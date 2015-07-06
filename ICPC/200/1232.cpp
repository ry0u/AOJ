#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

bool prime[10000000];
void Eratosthenes(int n) {
    rep(i,n) prime[i] = true;
    prime[1] = false;

    REP(i,2,(int)sqrt(n)) {
        if(prime[i]) {
            for(int j=0;i*(j+2)<n;j++) {
                prime[i*(j+2)] = 0;
            }
        }
    }
}

int main()
{
    Eratosthenes(100005);

    vector<int> p;
    REP(i,2,100005) {
        if(prime[i]) p.push_back(i);
    }

    ll m,a,b;
    while(cin >> m >> a >> b) {
        if(m == 0 && a == 0 && b == 0) break;

        ll c = 0,d = 0,vmax = 0;
        rep(i,p.size()) {
            if(p[i] > sqrt(m)) break;
            REP(j,i,p.size()) {
                
                ll res = p[i]*p[j];
                if(res > m) break;
                if(res <= m && vmax < res && a*p[j] <= b*p[i]) {
                    vmax = res;
                    c = p[i];
                    d = p[j];
                }
            }
        }

        cout << c << " " << d << endl;
    }
    return 0;
}
