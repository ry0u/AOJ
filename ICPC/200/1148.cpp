#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int cnt[10005][1500];

int main()
{
    int N,M;
    while(cin >> N >> M) {
        if(N == 0 && M == 0) break;
        
        int ptime[1005];
        memset(ptime,0,sizeof(ptime));

        int r;
        cin >> r;
        
        vector<pair<pair<int,int>,int> > v;
        rep(i,r) {
            int t,n,m,s;
            cin >> t >> n >> m >> s;

            if(s == 1) {
                ptime[n] = t;
            }
            else {
                pair<int,int> p = make_pair(ptime[n],t);
                v.push_back(make_pair(p,m));
            }
        }

        memset(cnt,0,sizeof(cnt));
        rep(i,v.size()) {
            int start = v[i].first.first;
            int end = v[i].first.second;
            int num = v[i].second;

            cnt[num][start]++;
            cnt[num][end+1]--;
        }

        rep(i,M+1) {
            REP(j,540,1500) {
                cnt[i][j+1] += cnt[i][j];
            }
        }

        vector<pair<pair<int,int>,int> > res;
        rep(i,M+1) {
            REP(j,540,1500) {
                if(cnt[i][j] > 0) {
                    int s = j;
                    while(cnt[i][j+1] > 0) {
                        j++;
                    }
                    
                    pair<int,int> p = make_pair(s,j);
                    res.push_back(make_pair(p,i));
                }
            }
        }


        int q;
        cin >> q;

        rep(i,q) {
            int s,t,m;
            cin >> s >> t >> m;
            
            int ans = 0;
            rep(j,res.size()) {
                int start = res[j].first.first;
                int end = res[j].first.second;
                int num = res[j].second;
                
                if(num != m) continue;

                if(end < s || t < start) continue;
                else if(start <= s && t <= end) {
                    ans += t - s;
                }
                else if(s < start && t <= end) {
                    ans += t - start;
                }
                else if(start <= s && end < t) {
                    ans += end - s;
                }
                else if(s < start && end < t) {
                    ans += end - start;
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}
