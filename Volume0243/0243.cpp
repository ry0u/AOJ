#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>
#include <map>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct Field
{
	vector<vector<char> >  f;
	int cnt;
};

bool check(vector<vector<char> > v,int y,int x)
{
   	char ret = v[0][0];
	rep(i,y)
	{
		rep(j,x)
		{
			if(ret != v[i][j]) return false;
		}
	}

	return true;
}

void change(vector<vector<char> > &v,int y,int x,char color)
{
	bool used[10][10];
	rep(i,10) rep(j,10) used[i][j] = false;

	queue<pair<pair<int,int>,char> > que;
	que.push(make_pair(make_pair(0,0),v[0][0]));
	used[0][0] = true;
	v[0][0] = color;

	while(que.size())
	{
		int nowy = que.front().first.first;
		int nowx = que.front().first.second;
	   	char nowc = que.front().second;

		que.pop();

		rep(i,4)
		{
			int ny = nowy + dy[i];
			int nx = nowx + dx[i];

			if(0 <= ny && ny < y && 0 <= nx && nx < x && !used[ny][nx])
			{
			    char nc = v[ny][nx];
				if(nc == nowc)
				{
					used[ny][nx] = true;
					v[ny][nx] = color;
					que.push(make_pair(make_pair(ny,nx),nc));
				}
			}
		}
	
	}


}

int main()
{
	int x,y;
	while(cin >> x >> y)
	{
		if(x == 0 && y == 0) break;

		vector<vector<char> > f;
		f.resize(y);

		rep(i,y)
		{
			rep(j,x)
			{
			    char s;
				cin >> s;
				f[i].push_back(s);
			}
		}
		
		Field field;
		field.f.resize(y);
		rep(i,y) copy(f[i].begin(),f[i].end(),back_inserter(field.f[i]));
		field.cnt = 0;

		queue<Field> que;
		que.push(field);
		int ans = 0;

		map<vector<vector<char> >,int> ma;

		while(que.size())
		{
			Field field = que.front();
			que.pop();

			if(check(field.f,y,x))
			{
				ans = field.cnt;
				break;
			}

			if(ma[field.f] == 0)
			{
				ma[field.f]++;

				Field next;
				next.f.resize(y);

				rep(i,y) copy(field.f[i].begin(),field.f[i].end(),back_inserter(next.f[i]));
				next.cnt = field.cnt + 1;

				change(next.f,y,x,'R');
				que.push(next);
			
				rep(i,y) next.f[i].clear();
				rep(i,y) copy(field.f[i].begin(),field.f[i].end(),back_inserter(next.f[i]));
				next.cnt = field.cnt + 1;

				change(next.f,y,x,'G');
				que.push(next);

				rep(i,y) next.f[i].clear();
				rep(i,y) copy(field.f[i].begin(),field.f[i].end(),back_inserter(next.f[i]));
				next.cnt = field.cnt + 1;
			
				change(next.f,y,x,'B');
				que.push(next);
			}
		}

		cout << ans << endl;
	}
}
