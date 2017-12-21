#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, m, i, j, ans, maxn;
int mapp[1005][1005]; 
int id[1005];
int od[1005];
int visited[1005];
int main() {
	freopen("test.txt","r",stdin);
	while(cin >> n >> m) {
		ans = 0;
		int now = 1;
		memset(mapp,0,sizeof(mapp));
		memset(id,0,sizeof(id));
		memset(od,0,sizeof(od));
		memset(visited,false,sizeof(visited));	
		for(int t = 1; t <= m; t++) {
			cin >> i >> j;
			if(i != j) {
				mapp[i][j] = 1;
				id[j] = 1;
				od[i] = 1;
			}
		}
		for(int t = 1; t <= n; t++) {//找到生产者 
			if(id[t] == 0 && od[t] != 0) {
				queue <int> q;
				cout << t << " ";
				q.push(t);
				while(!q.empty()) {
					j = q.front() ;
					q.pop() ;
					for(int i = 1; i <= n; i++) {
						if(mapp[j][i] == 1) {
							cout << i << " ";
							q.push(i);
						}
					}
				} 
			}
		}
		cout << ans << maxn << endl;
	}
	return 0;
}

