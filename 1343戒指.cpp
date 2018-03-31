1343:买戒指
难度： 倔强青铜    时间限制： 1000MS   空间限制： 16MB   提交数： 49   通过数： 12 题目来源: admin
题目内容
[2017 NUIST 程序设计竞赛]
C. 买戒指
题目描述
你和你的女朋友(tan90°)去买戒指，店里有好多戒指，编号为1，2，3……戒指上的钻石大小各不相同。你们从一堆戒指中随机抽取两枚并比较它们钻石的大小。在比较 m 次之后，你们看中了两枚戒指 a 和 b 。现在请你根据之前比较的信息判断这两枚戒指哪一枚的钻石更大。

输入描述
有多组输入。

每组第一行三个整数，a, b, m (1 <= a, b, c <= 1000)。

a 和 b 是最终要比较的两枚戒指，m 表示比较的次数。

接下来 m 行，每行两个整数 u, v，表示第 u 个戒指的钻石比第 v 个大。

输出描述
如果戒指 a 的钻石比 b 大，则输出 1。

如果戒指 a 的钻石比 b 小，则输出 -1。

如果根据现有信息，戒指 a 和 b 无法比较，则输出 0。

样例输入
2 3 4

1 2

2 4

1 3

4 3

样例输出
1
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int m[1005][1005], vis[1005];
int a, b, maxn;
bool dfs(int be ,int end) {
	queue<int> q;
	q.push(be);
	vis[be] = 1;
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		for(int i = 1; i <= maxn; i++) {
			if(m[t][i] && vis[i] == 0) {
				vis[i] = 1;
				if(i == end)	return true;
				q.push(i);
			} 
		}
	}
	return false;
}
int main() {
	int n, ta, tb;
	while(cin >> a >> b >> n) {
		maxn = 0;
		memset(m,0,sizeof(m));
		memset(vis,0,sizeof(vis));
		for(int i = 0; i < n; i++) {
			cin >> ta >> tb;
			maxn = max(maxn,max(ta,tb));
			m[tb][ta] = 1;
		}
		bool t1 = dfs(a,b);
		memset(vis,0,sizeof(vis));
		bool t2 = dfs(b,a);
		int ans;
		if(!t1 && !t2)	 ans = 0;
		if(t2)	 ans = 1;
		if(t1) 	 ans = -1;
		cout << ans << endl;
	}
	return 0;
}

