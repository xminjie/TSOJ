1306:背包问题
难度： 秩序白银    时间限制： 1000MS   空间限制： 16MB   提交数： 104   通过数： 23 题目来源: admin
题目内容
题目描述:
有n种物品，每种均有无穷多个。第i种物品的体积为Vi，重量为Wi。选一些物品装到一个体积容量为C的背包中，使得背包内物品在总体积不超过C的前提下重量尽量大。

输入描述：
第一行有两个整数n（1 <= n <= 100）和C（1 <= C <= 10000），用一个空格隔开，n表示货物种类数，C代表背包体积容量。接下来的n行每行包括两个在1到10000之间（包括1和10000）的整数Vi,Wi，分别表示物品的体积和重量。

输出描述：
包括一行，这一行只包含一个整数，表示在规定的背包体积大小内，背包内物品的最大重量

样例输入:
3 5

1 2

2 3

3 2

样例输出:
10
#include<iostream>
#include<cstring>
using namespace std;
int w[300],v[300],f[300010];
int V,n;
int main() {
	while(cin >> n >> V) {
		memset(f,0,sizeof(f));
		for(int i = 1; i <= n; i++) {
			int tw, tv;
			cin >> tw >> tv;
			w[i] = tw;
			v[i] = tv;
		}
		for(int i = 1; i <= n; i++) 
			for(int j = w[i]; j <= V; j++) 
				f[j] = max(f[j],f[j-w[i]] + v[i]);
		cout << f[V] << endl;
	}
	return 0;
}
