#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

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

int main() {
    string S;
    cin >> S;

    ll n;
    cin >> n;

    string s = S;

    vector<string> T = split(S,'+');
    vector<int> v;
    rep(i,T.size()) {
        vector<string> t = split(T[i],'*');
        rep(j,t.size()) {
            stringstream ss;
            ss << t[j];

            int temp;
            ss >> temp;
            v.push_back(temp);
        }
    }

    vector<char> t;
    rep(i,S.size()) {
        if(S[i] == '+' || S[i] == '*') t.push_back(S[i]);
    }
    
    ll b;
    stringstream ss;
    ss << v[0];
    ss >> b;

    rep(i,t.size()) {
        int r;
        stringstream ss2;

        ss2 << v[i+1];
        ss2 >> r;

        if(t[i] == '+') {
            b += r;
        }
        else b *= r;
    }

    while(true) {
        bool F = true;
        rep(i,t.size()) {
            if(t[i] == '*') {
                F = false;
                int l = v[i];
                int r = v[i+1];
                
                vector<int> temp;
                rep(j,i) {
                    temp.push_back(v[j]);
                }
                temp.push_back(l*r);

                REP(j,i+2,v.size()) {
                    temp.push_back(v[j]);
                }

                v.clear();
                copy(temp.begin(),temp.end(),back_inserter(v));

                vector<char> temp2;
                rep(j,i) temp2.push_back(t[j]);
                REP(j,i+1,t.size()) temp2.push_back(t[j]);
                t.clear();
                copy(temp2.begin(),temp2.end(),back_inserter(t));
                break;
            }
        }

        if(F) break;
    }

    ll a = 0;
    rep(i,v.size()) {
        a += v[i];
    }

    if(a == n && b == n) cout << "U" << endl;
    else if(a == n) cout << "M" << endl;
    else if(b == n) cout << "L" << endl;
    else cout << "I" << endl;

    return 0;
}
