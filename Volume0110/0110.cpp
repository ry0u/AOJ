#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

vector<string> split(const string &str, char delim) {
    vector<string> res;
    size_t current = 0, found;
    while((found = str.find_first_of(delim, current)) != string::npos) {
        res.push_back(string(str, current, found - current));
        current = found + 1;
    }
    res.push_back(string(str, current, str.size() - current));
    return res;
}

string func(string a,string b) {
    string ret;
    if(a.size() < b.size()) swap(a,b);

    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    int carry = 0;
    rep(i,b.size()) {
        int x = a[i] - '0';
        int y = b[i] - '0';
        int z = x + y + carry;

        carry = z / 10;
        ret.push_back('0' + (z%10));
    }

    REP(i,b.size(),a.size()) {
        int x = a[i] - '0';
        int z = x + carry;

        carry = z / 10;
        ret.push_back('0' + (z%10));
    }

    if(carry) ret.push_back('0' + carry);
    reverse(ret.begin(),ret.end());
    return ret;
}

int main() {
    string s;
    while(cin >> s) {
        vector<string> t = split(s,'+');
        vector<string> v = split(t[1], '=');

        string a = t[0], b = v[0] , c = v[1];
        bool flag = true;

        rep(i,10) {
            string A = a, B = b, C = c;
            rep(j,a.size()) {
                if(i == 0 && j == 0 && a.size() >= 2) continue;
                if(a[j] == 'X') A[j] = '0' + i;
            }

            rep(j,b.size()) {
                if(i == 0 && j == 0 && b.size() >= 2) continue;
                if(b[j] == 'X') B[j] = '0' + i;
            }

            rep(j,C.size()) {
                if(i == 0 && j == 0 && c.size() >= 2) continue;
                if(c[j] == 'X') C[j] = '0' + i;
            }

            bool ch = true;
            rep(j,A.size()) if(A[j] == 'X') ch = false;
            rep(j,B.size()) if(B[j] == 'X') ch = false;
            rep(j,C.size()) if(C[j] == 'X') ch = false;

            if(ch && func(A,B) == C) {
                cout << i << endl;
                flag = false;
            }
        }

        if(flag) cout << "NA" << endl;

    }
    return 0;
}
