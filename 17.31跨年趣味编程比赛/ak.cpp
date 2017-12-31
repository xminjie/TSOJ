AK
   时间限制： 1000MS   空间限制： 64MB   提交数： 1   通过数： 1 题目来源: zmq
题目内容
题目描述
众所周知 黄老师又双叒叕 AK 了！！！ 现在, 黄老师AK完打算提前离场, 不过他担心会不会自己的罚时过多而被其他人超过。 现在他打算手算一下罚时, 不过他的提交太多了, 黄老师 AK 完已经很累了。所以现在拜托你帮他编写一个程序去计算罚时。

已知每场比赛的题目代号为大写字母并且从 A 开始直到 Z（保证总题数不会超过26）, 黄老师总共有 n 次提交, 每一次提交为如下格式 :题目代号 结果 提交时间, 这里为了简化问题 题目结果只有 AC 和 WA 两种, 提交时间为比赛后多少分钟提交。

ACM-IPCP比赛中罚时如下计算, 一道题的罚时为 AC 的提交时间 + AC 之前的错误提交次数 × 20 分钟, 如果一道题在 30 分钟AC了, 但是之前错了两次, 那么罚时为 30 + 2 × 20 = 70 。 总的罚时是每道题的罚时累加, 一道题AC之后的再进行错误提交和正确提交都不增加罚时, 一道题如果没有AC, 那么不计算这道题的罚时。

输入提交记录已按时间升序排序, 不保证黄老师AK。

输入描述
第一行输入一个数字n, n代表黄老师提交的次数
接下来的n行, 每行输入 problem result time, 分别为这一次提交的题目代号 结果 时间

输出描述
输出本次比赛的总罚时

样例输入
3
A AC 20
B WA 30
B AC 50

样例输出
90

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
//	freopen("test.txt","r",stdin);
	int n;
	char c; string s; int t;
	while(cin >> n) {
		int sum = 0;  
		int time;
		int wa[200] = {0}, acti[200] = {0};
		bool isac[200] = {false};
		for(int i = 1; i <= n; i++) {
			cin >> c >> s >> t;
			if(isac[c] == false) {
				if(s == "AC")
				{
					isac[c] = true;
					acti[c] = t;
				}
				if(s == "WA")
					wa[c]++;
			}
		}
		for(int i = 0; i <= 190; i++) {
			if(isac[i] == true )
				{
					time = wa[i] * 20 + acti[i];
//					cout <<  wa[i] << ' ' << acti[i] << endl;
				}
			else
				time = 0;
			sum += time;
		}
		cout << sum << endl;
	}
	return 0;
}


