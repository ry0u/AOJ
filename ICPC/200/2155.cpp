#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main()
{
    int n,m;
    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;
        
        vector<pair<int,pair<int,int> > > v(m);
        rep(i,m) cin >> v[i].first >> v[i].second.first >> v[i].second.second;

        sort(v.begin(),v.end());

        bool T[20005];
        memset(T,0,sizeof(T));
        T[1] = true;
        set<int> st;
        st.insert(1);
        
        rep(i,m) {
            int time = v[i].first;
            int s = v[i].second.first;
            int t = v[i].second.second;

            if(T[s]) {
                T[t] = true;
                st.insert(t);
            }
        }
        
        cout << st.size() << endl;

    }

    return 0;
}
