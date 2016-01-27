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

int n;
vector<vector<int> > v(10, vector<int>(10));
bool flag = false;

bool can(int y,int x) {
    if(0 <= y && y < 10 && 0 <= x && x < 10) return true;
    return false;
}

vector<P> type(int y,int x,int t) {
    vector<P> p;
    p.push_back(P(y,x));

    if(t == 1) {
        p.push_back(P(y-1,x));
        p.push_back(P(y+1,x));
        p.push_back(P(y,x-1));
        p.push_back(P(y,x+1));
    } 
    if(t == 2) {
        for(int i = -1 ; i <= 1; i++) {
            for(int j = -1; j <= 1 ; j++) {
                int ny = y + i;
                int nx = x + j;
                if(ny == y && nx == x) continue;

                p.push_back(P(ny,nx));
            }
        }
    }

    if(t == 3) {
        for(int i = -1 ; i <= 1; i++) {
            for(int j = -1; j <= 1 ; j++) {
                int ny = y + i;
                int nx = x + j;
                if(ny == y && nx == x) continue;

                p.push_back(P(ny,nx));
            }
        }

        p.push_back(P(y-2,x));
        p.push_back(P(y+2,x));
        p.push_back(P(y,x-2));
        p.push_back(P(y,x+2));
    }

    return p;
}

bool ch(int y,int x,int t) {
    vector<P> p = type(y,x,t);
    rep(i,p.size()) {
        int ny = p[i].first;
        int nx = p[i].second;
        if(!can(ny,nx)) return false;
        if(v[ny][nx] <= 0) return false;
    }

    return true;
}

void fill(int y, int x,int t,int w) {
    vector<P> p = type(y,x,t);
    rep(i,p.size()) {
        v[p[i].first][p[i].second] += w;
    }
}

void dfs(vector<P> p,vector<int> t) {
    cout << " ------- dfs -----" << endl;
    cout << p.size() << " " << t.size() << endl;

    if(p.size() == n) {
        bool f = true;

        rep(i,10) {
            rep(j,10) {
                if(v[i][j] != 0) f = false;
            }
        }

        if(f) {
            rep(i,p.size()) {
                cout << p[i].second << " " << p[i].first << " " << t[i] << endl;
            }

        }

        return;
    }

    rep(i,10) {
        rep(j,10) {
            if(v[i][j] == 0) continue;
            REP(k,1,4) {
                if(ch(i,j,k)) {
                    fill(i,j,k,-1);
                    p.push_back(P(i,j));
                    t.push_back(k);

                    dfs(p,t);
    
                    fill(i,j,k,+1);
                    p.pop_back();
                    t.pop_back();
                }
            }
        }
    }
}


int main() {
    cin >> n;

    rep(i,10) {
        rep(j,10) {
            cin >> v[i][j];
        }
    }

    vector<P> p;
    vector<int> t;

    dfs(p,t);

    return 0;
}
