



1373:计算器1
难度： 倔强青铜    时间限制： 1000MS   空间限制： 64MB   提交数： 39   通过数： 14
题目内容
题目描述：
给定一行表达式，中间没有空格，输出表达式的计算结果，测试数据保证int范围之内，这是简单的一个题目，只涉及加法和减法。

输入描述：
一行表达式

输出描述：
表达式的计算结果

样例输入：
12+21-0

样例输出：
33

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int res, a;
	char c;
	while(cin >> res){
		while(scanf("%c",&c)) {
			if(c=='\n')
				break;
			cin >> a;
			if(c=='+')
				res += a;
			if(c=='-')
				res -= a;
		}
		cout << res << endl;
	}
}


