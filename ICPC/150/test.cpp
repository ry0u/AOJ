#include <stdio.h>
#include <string.h>
#include <iostream>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    cout << n << endl;

    char s[52];
    rep(i,n) {
        char c;
        scanf(" %c",&c);
        s[i] = c;
        cout << s[i] << endl;
    }
    return 0;
}
