1142:Encoding
难度： 秩序白银    时间限制： 1000MS   空间限制： 16MB   提交数： 57   通过数： 14 题目来源: nuistoj
题目内容
题目描述:
Given a string containing only "A" - "Z", we could encode it using the following method:

1. Each sub-string containing k same characters should be encoded to "kX" where "X" is the only character in this sub-string.

2. If the length of the sub-string is 1, "1" should be ignored.
输入描述：
The first line contains an integer N (1 <= N <= 100) which indicates the number of test cases. The next N lines contain N strings. Each string consists of only "A" - "Z" and the length is less than 10000.

输出描述：
For each test case, output the encoded string in a line.

样例输入:
2

ABC

ABBCCC

样例输出:
ABC

A2B3C
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n; 
	string s;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s;
		for(int j = 0, k; j < s.size(); j = k) {
			for(k = j + 1; s[k] == s[j]; k++) ;
			if(k - j > 1) 	cout << k-j;
			cout << s[j];
		}
		cout << endl;
	}
	return 0;
}
