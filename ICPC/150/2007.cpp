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
    bool first = true;
    while(cin >> n && n) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;

        int m = a*10 + b*50 + c*100 + d*500;
        m -= n;

        d -= m/500;
        m %= 500;

        c -= m/100;
        m %= 100;

        b -= m/50;
        m %= 50;

        a -= m/10;
        m %= 10;

        if(!first) cout << endl;

        if(a > 0) cout << 10 << " " << a << endl;
        if(b > 0) cout << 50 << " " << b << endl;
        if(c > 0) cout << 100 << " " << c << endl;
        if(d > 0) cout << 500 << " " << d << endl;

        first = false;
    }

    return 0;
}
