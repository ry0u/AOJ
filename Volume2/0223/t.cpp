#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

class State{
public:
  int x1,y1,x2,y2,cost;

  State(int tx1,int ty1,int tx2,int ty2,int tcost){
    x1 = tx1;
    y1 = ty1;
    x2 = tx2;
    y2 = ty2;
    cost = tcost;
  }
};

int w,h;
bool t[52][52];
bool closed[52][52][52][52];

int dx1[] = {-1,1,0,0};
int dx2[] = {1,-1,0,0};
int dy1[] = {0,0,1,-1};
int dy2[] = {0,0,-1,1};

int main(void){
  while(cin>>w>>h && (w||h)){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    x1--; y1--; x2--; y2--;

    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        cin>>t[i][j];
      }
    }

    int ans = -1;
    queue<State> open;

    memset(closed,0,sizeof(closed));
    closed[x1][y1][x2][y2] = true;
    open.push(State(x1,y1,x2,y2,0));

    while(!open.empty()){
      State st = open.front(); open.pop();
      if(st.cost >= 100) break;

      if(st.x1 == st.x2 && st.y1 == st.y2){
        ans = st.cost;
        break;
      }

      for(int i=0;i<4;i++){
        int nx1 = st.x1 + dx1[i];
        int ny1 = st.y1 + dy1[i];
        int nx2 = st.x2 + dx2[i];
        int ny2 = st.y2 + dy2[i];
        State nst = st;
        nst.cost++;

        if(nx1>=0 && nx1<w && ny1>=0 && ny1<h && !t[ny1][nx1]){
          nst.x1 = nx1;
          nst.y1 = ny1;
        }
        if(nx2>=0 && nx2<w && ny2>=0 && ny2<h && !t[ny2][nx2]){
          nst.x2 = nx2;
          nst.y2 = ny2;
        }

        if(!closed[nst.x1][nst.y1][nst.x2][nst.y2]){
          closed[nst.x1][nst.y1][nst.x2][nst.y2] = true;
          open.push(nst);
        }
      }
    }

    if(ans == -1)
      cout<<"NA\n";
    else
      cout<<ans<<endl;
  }

  return 0;
}
