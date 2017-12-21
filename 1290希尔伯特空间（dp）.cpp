#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int dp[10000][10000];
	int n, c;
	while(cin >> c >> n) {
		memset(dp,0,sizeof(dp));
		for(int i = 1; i <= n; i++) {
			int v;
			cin >> v;
			for(int j = 1; j <= c; j++) {
				if(j >= v) {
					dp[i][j] = max(dp[i-1][j],dp[i-1][j-v] + v);
				}
				else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		cout << c - dp[n][c] << endl;
	}
	return 0;
}


