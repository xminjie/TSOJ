

吃饼干
   时间限制： 1000MS   空间限制： 64MB   提交数： 1   通过数： 1 题目来源: zmq
题目内容
题目描述：
众所不周知， 在某两个喜欢吃饼干的小朋友A和B之间展开了一场激烈的"吃饼干大战"! 由于饼干太大，所以他们一次只能吃 一个或两个饼干，他们约定谁吃到最后一个饼干谁就是真正的吃货, 由于他们都非常想赢得这场比赛，所以他们都会采用最佳的吃饼干策略。

输入描述
多组输入, 每组输入一行, 包括空格隔开的一个整数n和一个字母c,n代表饼干的总数,若c是A, 则A先吃, 否则, 若c是B, 则B先吃。

输出描述
如果A赢了, 输出 "A win!", 如果B赢了, 输出"B win!"

样例输入
2 A 
12 A

样例输出
A win!
B win!


#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int n;
	char c;
	while(cin >> n >> c) {
		n = n%3;
		if(n == 0) {
			if(c == 'B')
				cout << "A win!\n";
			else 
				cout << "B win!\n";
		}
		else {
			if(c == 'A')
				cout << "A win!\n";
			else 
				cout << "B win!\n";
		}
	}
	return 0;
}


