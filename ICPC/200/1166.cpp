#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

struct edge {
    int from,to;
    int cost;

    edge(int t,int c) : to(t),cost(c) {}
    edge(int f,int t,int c) : from(f),to(t),cost(c) {}

    bool operator<(const edge &e) const {
        return cost < e.cost;
    }
};

vector<edge> G[1005];
int d[1005];

void dijkstra(int s,int n) {
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+n,INF);

    d[s] = 0;
    que.push(P(0,s));

    while(que.size()) {
        P p = que.top();
        que.pop();

        int v = p.second;
        if(d[v] < p.first) continue;

        rep(i,G[v].size()) {
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

int main() {
    int n,m;

    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;

        rep(i,n*m) {
            G[i].clear();
        }

        int type;
        rep(i,m) {
            rep(j,n-1) {
                cin >> type;
                if(type == 0) {
                    int s = n*i + j;
                    int t = n*i + j+1;
                    
                    G[s].push_back(edge(t,1));
                    G[t].push_back(edge(s,1));
                }
            }

            if(i == m-1) break;
            rep(j,n) {
                cin >> type;
                if(type == 0) {
                    int s = n*i + j;
                    int t = n*(i+1) + j;

                    G[s].push_back(edge(t,1));
                    G[t].push_back(edge(s,1));
                }
            }
        }

        
        dijkstra(0,n*m);

        if(d[n*m-1] == INF) cout << 0 << endl;
        else cout << d[n*m-1] + 1 << endl;
    }


    return 0;
}
