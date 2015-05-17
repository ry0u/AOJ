#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

string fill_m(string s,int m) {
    string ret = s;
    rep(i,m-s.size()) {
        ret = "0" + ret;
    }
    return ret;
}

string next(string s,int m) {
    sort(s.begin(),s.end());
    string ret = s;
    sort(s.begin(),s.end(),greater<char>());
    string ret2 = s;

    int a,b;
    stringstream ss;
    ss << ret;
    ss >> a;

    stringstream ss2;
    ss2 << ret2;
    ss2 >> b;

    b -= a;

    stringstream ss3;
    ss3 << b;
    return fill_m(ss3.str(),m);
}

int main()
{
    int n,m;
    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;
        
        stringstream ss;
        ss << n;

        string ret = fill_m(ss.str(),m);
        vector<string> v;
        v.push_back(ret);
        
        REP(i,1,25) {
            v.push_back(next(v[i-1],m));
        }

        int ans = 25,ai,aj;
        rep(i,25) {
            REP(j,i+1,25) {
                if(v[i] == v[j]) {
                    if(ans > j) {
                        ans = j;
                        ai = i;
                    }
                }
            }
        }
        
        stringstream ss2;
        rep(i,v[ai].size()-1) {
            if(v[ai][i] == '0') continue;
            else {
                REP(j,i,v[ai].size()-1) ss2 << v[ai][j];
                break;
            }
        }

        ss2 << v[ai][v[ai].size()-1];

        cout << ai << " " << ss2.str() << " " << ans-ai << endl;
    }

    return 0;
}
