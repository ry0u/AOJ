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

int main()
{
    int n;
    while(cin >> n && n) {
        vector<string> v(n);
        rep(i,n) cin >> v[i];

        vector<int> res(n);
        rep(i,n) {
            if(v[i] == "x") res[i] = 0;
            else {
                stringstream ss;
                ss << v[i];
                ss >> res[i];
            }
        }

        bool flag = true;
        rep(i,n-1) {
            if(v[i] == "x" && v[i+1] == "x") flag = false;
        }

        if(!flag) {
            cout << "none" << endl;
        }
        else {
            bool zig = true;
            
            rep(i,n-1) {
                if(v[i] == "x" || v[i+1] == "x") continue;
            
                if(i%2 == 0) {
                    if(res[i] >= res[i+1]) zig = false;
                }
                else {
                    if(res[i] <= res[i+1]) zig = false;
                }
            }


            if(!zig) {
                cout << "none" << endl;
            }
            else {
                int M = 1000000000;
                int l = -M-5;
                int r = M+5;

                rep(i,n) {
                    if(v[i] != "x") continue;

                    if(i%2 == 0) {
                        if(i == 0) {
                            r = min(r,res[i+1]-1);
                        }
                        if(0 < i && i < n-1) {
                            r = min(r,res[i-1]-1);
                            r = min(r,res[i+1]-1);
                        }
                        if(i == n-1) {
                            r = min(r,res[i-1]-1);
                        }
                    }
                    else {
                        if(i == 0) {
                            l = max(l,res[i+1]+1);
                        }
                        if(0 < i && i < n-1) {
                            l = max(l,res[i-1]+1);
                            l = max(l,res[i+1]+1);
                        }
                        if(i == n-1) {
                            l = max(l,res[i-1]+1);
                        }
                    }
                }

                if(l == r) {
                    cout << l << endl;
                }
                else if(l > r) {
                    cout << "none" << endl;
                }
                else {
                    cout << "ambiguous" << endl;
                }
            }

        }


    }

    return 0;
}
