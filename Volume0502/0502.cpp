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

struct Dice {
    int f[6];

    Dice() {
        f[0] = 1; f[1] = 6; f[2] = 2; f[3] = 3; f[4] = 5; f[5] = 4;
    }

    void roll(int i,int j,int k,int l) {
        int t = f[i]; f[i] = f[j]; f[j] = f[k]; f[k] = f[l]; f[l] = t;
    }

    void move(char ch) {
        if(ch == 'E') roll(0,5,1,3);
        if(ch == 'W') roll(0,3,1,5);
        if(ch == 'N') roll(0,2,1,4);
        if(ch == 'S') roll(0,4,1,2);
        if(ch == 'R') roll(2,3,4,5);
        if(ch == 'L') roll(2,5,4,3);
    }
};

int main() {
    int n;

    while(cin >> n && n) {
        int sum = 1;
        Dice dice;
        rep(i,n) {
            string s;
            cin >> s;


            dice.move(s[0]);
            sum += dice.f[0];
        }

        cout << sum << endl;
    }

    return 0;
}
