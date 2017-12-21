#include <iostream>
#include <cstring>
using namespace std;
int n, m, i, j, ans;
int map[1005][1005]; 
int id[1005];
int od[1005];
int  now; 
int dfs(int begin ) {
	if(od[begin] == 0) {
		if(ans < now) {
			ans = now;
			return 0;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(map[begin][i] == 1) {
			now++;
			dfs(i);
			now--;//回溯，类似遛牛的flag; 
		}
	}
}
int main() {
	while(cin >> n >> m) {
		ans = 0;
		now = 1;
		memset(map,0,sizeof(map));
		memset(id,0,sizeof(id));
		memset(od,0,sizeof(od));		
		for(int t = 1; t <= m; t++) {
			cin >> i >> j;
			if(i != j) {
				map[i][j] = 1;
				id[j] = 1;
				od[i] = 1;
			}
		}
//		int temp = 0;
//		for(int i = 1; i <= n; i++) {
//			if(id[i] == 0 && od[i] == 0) {
//				temp++;
//			}
//		} 
		for(int t = 1; t <= n; t++) {//找到生产者 
			if(id[t] == 0 && od[t] != 0) {
				dfs(t);
			}
		}
		cout << ans << endl;
	}
	return 0;
}

