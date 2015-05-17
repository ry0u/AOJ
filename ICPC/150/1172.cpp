#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

bool prime[10000000];
void Eratosthenes(int n)
{
    rep(i,n) prime[i] = true;
    prime[1] = false;

    REP(i,2,(int)sqrt(n))
    {
        if(prime[i])
        {
            for(int j=0;i*(j+2)<n;j++)
            {
                prime[i*(j+2)] = 0;
            }
        }
    }
}

int main()
{
    Eratosthenes(10000000);
    int n;
    while(cin >> n && n)
    {
        int ans = 0;
        REP(i,n+1,2*n+1) {
            if(prime[i]) ans++;
        }
        
        cout << ans << endl;
    }

    return 0;
}
