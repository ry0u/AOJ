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

int main()
{
    int n;
    while(cin >> n && n) {
        int ans = 0;
        
        int m = sqrt(n) + 1;
        REP(i,1,m) {
            int a = i*i;
            if(a == n) ans++;
            REP(j,i,m) {
                int b = j*j;
                if(a + b == n) ans++;
                REP(k,j,m) {
                    int c = k*k;
                    if(a + b + c == n) ans++;
                    REP(l,k,m) {
                        int d = l*l;

                        if(a + b + c + d == n) ans++;
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
