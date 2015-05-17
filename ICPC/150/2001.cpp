#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main()
{
    int n,m,a;
    while(cin >> n >> m >> a) {
        if(n == 0 && m == 0 && a == 0) break;
        
        vector<pair<int,pair<int,int> > > v;

        rep(i,m) {
            int h,p,q;
            cin >> h >> p >> q;
            p--;
            q--;

            v.push_back(make_pair(h,make_pair(p,q)));
        }

        sort(v.begin(),v.end(),greater<pair<int,pair<int,int> > >());

        int d[105];
        memset(d,0,sizeof(d));

        rep(i,n) d[i] = i;
               
        rep(i,v.size()) {
            swap(d[v[i].second.first],d[v[i].second.second]);
        }

        rep(i,n) {
            if(d[i] == a-1) cout << i+1 << endl;
        }
    }

    return 0;
}
