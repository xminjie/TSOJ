睡神
   时间限制： 1000MS   空间限制： 64MB   提交数： 2   通过数： 1 题目来源: zmq
题目内容
题目描述
tiejun 特别喜欢睡觉，但是由于他更热爱学(chi)习(ji)， 所以他睡觉的时间并不是连续的， 已知一天之中他有间断的分别睡了a1, a2, ... , an小时。 但是，tiejun 每天都要睡 25个小时才能满足他的睡眠需求，tiejun 想知道他这一天是不是满足了自己的睡眠需求，　但是他特别忙(lan)， 所以请你编写一个程序，帮他计算今天是否满足了睡眠需求。如果你完成了任务，tiejun 将会送给你一个 Accepted。

输入描述
多组输入，每组第一行输入一个整数n,下面一行输入n个数字,代表tiejun每次睡觉的时间。

输出描述
一行，如果满足25个小时输出 "YES", 否则输出"NO"

样例输入
5
3 3 3 3 3

样例输出
NO

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int n, t;
	while(cin >> n) {
		int sum = 0;
		for(int i = 0; i < n; i++) {
			cin >> t;
			sum += t;
		}
		if(sum >= 25)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	} 
	return 0;
}


