#include <iostream>
#include <cstring>
using namespace std;
int n, m, i,j, ans;
int map[1005][1005]; 
int id[1005];
int od[1005];
int dfs(int begin ) {
	if(od[begin] == 0) {
		ans++;
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		if(map[begin][i] == 1) {
			dfs(i);
		}
	}
}
int main() {
	while(cin >> n >> m) {
		ans = 0;
		memset(map,0,sizeof(map));
		memset(id,0,sizeof(id));
		memset(od,0,sizeof(od));		
		for(int t = 1; t <= m; t++) {
			cin >> i >> j;
			map[i][j] = 1;
			id[j] = 1;
			od[i] = 1;
		}
		for(int t = 1; t <= n; t++) {
			if(id[t] == 0) {
				dfs(t);
			}
		}
		cout << ans << endl;
	}
	return 0;
}

