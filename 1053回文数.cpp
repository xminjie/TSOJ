1053:回文数
难度： 秩序白银    时间限制： 1000MS   空间限制： 64MB   提交数： 86   通过数： 35 题目来源: nuistoj
题目内容
题目描述:
判断一个正整数是否为回文数。回文数是这样的数：一个正整数从左往右读和从右往左读都是一样的数

输入描述：
输入一个整数，占一行：12321

输出描述：
输出占一行，是否为回文数，是输出：yes，不是输出：no

样例输入:
1234

121

454

样例输出:
no

yes

yes
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string res, s;
	while(cin >> s) {
		res = s;
		reverse(s.begin() ,s.end() );
		if(res == s )	cout << "yes\n";
		else			cout << "no\n";
	} 
return 0;
}

