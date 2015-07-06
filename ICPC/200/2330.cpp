#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;

    ll cnt = 0;
    ll res = 1;

    while(res < n) {
        res *= 3;
        cnt++;
    }

    cout << cnt << endl;
    

    return 0;
}
