#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

string same(string s,string t) {
    string ret = s;
    rep(i,s.size()) {
        if(s[i] == t[i]) continue;
        else ret[i] = 'X';
    }

    return ret;
}

string Xor(string s,string t) {
    string ret = s;
    rep(i,s.size()) {
        if(s[i] == t[i]) ret[i] = '0';
        else ret[i] = '1';
    }
    
    return ret;
}

int main() {

    int n,m,q;
    while(cin >> n >> m >> q) {
        if(n == 0 && m == 0 && q == 0) break;

        vector<string> s(q),b(q);
        rep(i,q) {
            cin >> s[i] >> b[i];
        }

        string ori = "";
        rep(i,n) ori += "0";

        vector<string> ins;
        string pre = ori;
        rep(i,q) {
            pre = Xor(pre,s[i]);
            ins.push_back(pre);
        }

        vector<int> v(n);
        rep(i,n) v[i] = i;

        stringstream ans;

        rep(i,m) {
            vector<string> a0,b1;

            rep(j,q) {
                if(b[j][i] == '0') {
                    a0.push_back(ins[j]);
                }
                else {
                    b1.push_back(ins[j]);
                }
            }

            string res;
            if(a0.size() == 0)  res = ori;
            else res = a0[0];

            rep(j,a0.size()) {
                res = same(res,a0[j]);
            }

            string res2;
            if(b1.size() == 0) res2 = ori;
            else res2 = b1[0];

            rep(j,b1.size()) {
                res2 = same(res2,b1[j]);
            }

            set<int> st;
            rep(j,n) {
                if(res[j] == 'X' || res2[j] == 'X') continue;
                if(res[j] == '0' && res2[j] == '1') {
                    st.insert(j);
                }
            }

            if(st.size() == 1) {
                set<int>::iterator ite = st.begin();
                if(0 <= *ite && *ite <= 9) {
                    ans << *ite;
                }
                else {
                    int id = *ite - 10;
                    ans << char('A' + id);
                }
    
                v.erase(remove(v.begin(),v.end(),*ite),v.end());
            }
            else ans << "?";

        }
        
        string res = ans.str();
        if(v.size() == 1) {
            rep(i,res.size()) {
                if(res[i] == '?') {
                    if(0 <= v[0] && v[0] <= 9) {
                        cout << v[0];
                    }
                    else {
                        int id = v[0] - 10;
                        cout << char('A' + id);
                    }
                }
                else cout << res[i];
            }
            cout << endl;
        }
        else cout << res << endl;


    }

    return 0;
}
