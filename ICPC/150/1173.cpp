#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    string s;
    while(true)
    {
        getline(cin,s);
        if(s == ".") break;
        
        stack<char> st;
        bool flag = true;
        rep(i,s.size()) {
            if(!flag) break;

            if(s[i] == '(') {
                st.push(s[i]);
            }
            if(s[i] == ')') {
                if(st.size() == 0) flag = false;
                else {
                    if(st.top() == '(') st.pop();
                    else flag = false;
                }
            }
            if(s[i] == '[') {
                st.push(s[i]);
            }
            if(s[i] == ']') {
                if(st.size() == 0) flag = false;
                else {
                    if(st.top() == '[') st.pop();
                    else flag = false;
                }
            }
        }

        if(flag && st.size() == 0) cout << "yes" << endl;
        else cout << "no" << endl;
        
    }

    return 0;
}
