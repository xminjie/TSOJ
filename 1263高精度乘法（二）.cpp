1263:高精度乘法（二）
难度： 秩序白银    时间限制： 1000MS   空间限制： 16MB   提交数： 44   通过数： 14 题目来源: nuistoj
题目内容
题目描述:
两个长度小于 100 位的正整数，求其乘积。

输入描述：
第一行是一个正整数 n (n < 50)，表示有 n 组测试数据，每组测试数据由两行构成。每行表示一个测试数据，每个测试数据是长度小于 100 位的正整数。

输出描述：
n 行，每行一个计算结果。

样例输入:
2

11111

22222

1937

2931

样例输出:
246908642

5677347
#include <iostream>
#include <algorithm>
using namespace std;
string mul(string s1, string s2) {
	string ans = "";
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	int l1 = s1.length() , l2 = s2.length();
	vector<int> v(s1.size() + s2.size(), 0);
	for(int i = 0; i < s1.size(); i++) {
		for(int j = 0; j < s2.size(); j++) {
			int t = (s1[i] - '0') * (s2[j] - '0') + v[i+j];
			v[i+j+1] += t / 10;
			v[i+j] = t % 10;
		}
	}
	int j;
	for(j = l1 + l2 - 1; v[j] == 0; j--)	;
	for(; j >= 0; j--)	ans += to_string(v[j]);
	if(ans == "")	return "0";
	return ans; 
}
int main() {
	int n;
	cin >> n;
	string s1, s2;
	for(int i = 0; i < n; i++) {
		cin >> s1 >> s2;
		cout << mul(s1,s2) << endl;
	} 
	return 0;
}

