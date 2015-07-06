#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main()
{
    int n,m;
    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;
        
        map<string,pair<int,int> > ma;
        
        rep(i,n) {
            string s;
            int a,b;
            cin >> s >> a >> b;
            
            ma[s] = make_pair(b-a+1,b);
        }

        rep(i,m) {
            int x;
            cin >> x;
        
            bool flag = true;
            map<string,pair<int,int> >::iterator ite;
            for(ite = ma.begin();ite != ma.end();ite++) {
                int s = ite->second.first;
                int e = ite->second.second;

                if(s <= x && x <= e) {
                    cout << ite->first << " " << x - s + 1 << endl;
                    flag = false;
                    break;
                }
            }

            if(flag) cout << "Unknown" << endl;
        }
    }

    return 0;
}
