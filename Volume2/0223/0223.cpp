#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct Data
{
	int tx,ty,kx,ky,cost;

	Data(int tx,int ty,int kx,int ky,int cost) : tx(tx),ty(ty),kx(kx),ky(ky),cost(cost) {}
};

int main()
{
	int x,y;
	while(cin >> x >> y)
	{
		if(x == 0 && y == 0) break;

		int tx,ty,kx,ky;
		cin >> tx >> ty >> kx >> ky;

		tx--;
		ty--;
		kx--;
		ky--;

		int field[55][55];
		memset(field,0,sizeof(field));

		rep(i,y) rep(j,x) cin >> field[i][j];

	   	bool used[52][52][52][52];
		rep(i,52) rep(j,52) rep(k,52) rep(l,52) used[i][j][k][l] = false;
		used[tx][ty][kx][ky] = true;

		queue<Data> que;
		que.push(Data(tx,ty,kx,ky,0));
		
		bool flag = false;
		int ans;

		while(que.size())
		{
			Data data = que.front();
			que.pop();

			if(data.cost >= 100) break;

			if(data.tx == data.kx && data.ty == data.ky)
			{
				flag = true;
				ans = data.cost;
				break;
			}

			rep(i,4)
			{
				int ntx = data.tx + dx[i];
				int nty = data.ty + dy[i];
				int nkx = data.kx + dx[(i+2)%4];
				int nky = data.ky + dy[(i+2)%4];

				Data nd(data.tx,data.ty,data.kx,data.ky,data.cost+1);

				if(0 <= ntx && ntx < x && 0 <= nty && nty < y && field[nty][ntx] == 0)
				{
					nd.tx = ntx;
					nd.ty = nty;
				}

				if(0 <= nkx && nkx < x && 0 <= nky && nky < y && field[nky][nkx] == 0)
				{
					nd.kx = nkx;
					nd.ky = nky;
				}

				if(!used[nd.tx][nd.ty][nd.kx][nd.ky])
				{
					used[nd.tx][nd.ty][nd.kx][nd.ky] = true;
					que.push(nd);
				}
			}

		}

		if(flag) cout << ans << endl;
		else cout << "NA" << endl;
	}
}
