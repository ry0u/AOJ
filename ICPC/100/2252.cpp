#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    string s;
    while(cin >> s)
    {
        if(s == "#") break;
        
        int cnt = 0;
        string t = "yuiophjklnm*";
        bool right = true;
        if(t.end() != find(t.begin(),t.end(),s[0])) {
            right = false;
        }
        rep(i,s.size()) {
            if(right) {
                if(t.end() != find(t.begin(),t.end(),s[i])) {
                    cnt++;
                    right = false;
                }
            }
            else {
                if(t.end() == find(t.begin(),t.end(),s[i])) {
                    cnt++;
                    right = true;
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
