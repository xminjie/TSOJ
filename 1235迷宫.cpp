1235:迷宫
难度： 秩序白银    时间限制： 1000MS   空间限制： 64MB   提交数： 45   通过数： 10 题目来源: nuistoj
题目内容
题目描述:
成功战胜了咕噜后，Ipomy 进入到了一个迷宫当中。这个迷宫的规格为 m * n，只有一个入口和一个出口。Ipomy 相信，只要走出这个迷宫，阿兹特克宝藏就在眼前了。他想要知道离开迷宫最少需要走多少步，请你编程帮助他计算一下。

输入描述：
多组输入。

每组输入的第一行为两个整数 m 和 n，表示迷宫的规格，保证 1 <= n, m <= 100。

接下来的 m 行，每行 n 个数，描述迷宫每个格子的信息。其中，0 表示格子可以移动，1 表示格子上面有障碍物，不能移动。每组输入数据均将入口定在左上角，出口定在右下角，这两个格子的输入数值均为 0。

输出描述：
多组输出。

每组输出占据一行，为一个整数，表示最短路径。当无法离开迷宫时，输出 -1。

样例输入:
4 5

0 1 1 0 0

0 1 0 0 0

0 0 0 1 0

1 1 1 0 0

3 3

0 1 0

0 1 0

0 1 0

样例输出:
9

-1

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int map[105][105];
int vis[105][105];
int x[] = {-1,0,1,0};
int y[] = { 0,1,0,-1};
int m, n, t;
struct pos{
	int x, y, step;
}; 
int f(void) {
		queue <pos> q;
		pos p;
		int tx,ty,tstep;
		vis[0][0] = true;
		p.x = p.y = p.step = 0;//记录当前走了几步 
		q.push(p);
		int cnt = 0;
		while(!q.empty()) {
			cnt++;
			tx = q.front().x;
			ty = q.front().y; 
			tstep = q.front().step;
			q.pop();
			for(int i = 0; i < 4; i++) {
				if(tx+x[i] >=0 && tx+x[i] < m && ty+y[i] >= 0 && ty+y[i] < n 
				&& tx+x[i] == m-1 && ty+y[i] == n-1 && map[tx+x[i]][ty+y[i]] == 0) {
					cout << tstep+1 << endl;//找到出口要及时及结束 
					return 0;
				}
				if(tx+x[i] >=0 && tx+x[i] < m && ty+y[i] >= 0 && ty+y[i] < n && 
				vis[tx+x[i]][ty+y[i]] == false && map[tx+x[i]][ty+y[i]] == 0 ) {
					p.x = tx+x[i];
					p.y = ty+y[i];
					p.step = tstep+1;//该步的下一步就要加+1 
					q.push(p);
					vis[tx+x[i]][ty+y[i]] = true;
				} 
			}
		}
		cout << -1 << endl;
		return 0;
}
int main() {
//	freopen("test.txt","r",stdin);
	while(cin >> m >> n) {
		memset(map,0,sizeof(map));
		memset(vis,false,sizeof(vis));
		for(int i = 0; i < m; i++) 
			for(int j = 0; j < n; j++) 
				cin >> map[i][j];
		f();
	}
	return 0;
}

