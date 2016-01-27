#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int a,b,c;
	cin >> a >> b >> c;

	if(a == 1 && b == 0 && c == 0) cout << "Close" << endl;
	else if(a == 0 && b == 1 && c == 0) cout << "Close" << endl;
	else if(a == 1 && b == 1 && c == 0) cout << "Open" << endl;
	else if(a == 0 && b == 0 && c == 1) cout << "Open" << endl;
	else if(a == 0 && b == 0 && c == 0) cout << "Close" << endl;

}
