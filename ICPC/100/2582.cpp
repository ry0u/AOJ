#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int n;
    while(cin >> n && n){

        int ans = 0;
        bool l = false,r = false,next = true;

        rep(i,n) {
            string s;
            cin >> s;

            if(s == "lu") {
                l = true;
                if(l && r && next) {
                    ans++;
                    next = false;
                }
            }
            else if(s == "ru") {
                r = true;
                if(l && r && next) {
                    ans++;
                    next = false;
                }
            }
            else if(s == "ld") {
                l = false;
                if(!l && !r && !next) {
                    ans++;
                    next = true;
                }
            }
            else if(s == "rd") {
                r = false;
                if(!l && !r && !next) {
                    ans++;
                    next = true;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
