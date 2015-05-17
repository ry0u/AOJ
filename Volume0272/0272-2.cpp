#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n;
	while(cin >> n && n)
	{
		int P1[40005],P2[40005],T[40005];

		REP(i,1,n+1) cin >> P1[i];
		REP(i,1,n+1) cin >> P2[i];

		sort(P1+1,P1+n+1,greater<int>());
		sort(P2+1,P2+n+1,greater<int>());

		rep(i,n+1) T[i] = 0;

		int s=1,t=1;
		while(s <= n && t <= n)
		{
			cout << s << " " << t << " ";
			while(P1[t] > P2[s] && t <= n) t++;
			cout << "afe:" << t << endl;
			if(t <= n && P2[s] >= P1[t])
			{
				T[t]++;
				t++;
				s++;
			}
		}

		REP(i,1,n+1) T[i] += T[i-1];
		
		int k=-1;
		REP(i,1,n+1)
		{
			if((i-T[i]) >= (i+2)/2)
			{
				k=i;
				break;
			}
		}
		
		if(k == -1 || k == n) cout << "NA" << endl;
		else cout << k << endl;
	}

	return 0;
}
