



1006:最小公倍数
难度： 秩序白银    时间限制： 1000MS   空间限制： 64MB   提交数： 92   通过数： 36
题目内容
题目描述:
给定2个数，a和b(3 < a,b < =10000)，求出a和b的最小公倍数。

输入描述：
多组输入，输入的第一行为一个正整数n，表示接下来有n组数据，每一行为两个正整数a，b(3 < a,b < =10000)

输出描述：
对于每一组数据，求出a和b的最小公倍数。

样例输入:
2

2 4

3 5

样例输出:
4

15
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int a, b, t, a1, b1;
	int n;
	while( cin >> n ) {
		for(int i = 0; i < n; i++) {
			cin >> a >> b;
			a1 = a; 
			b1 = b;
			while( a % b) {
				t = a % b;
				a = b;
				b = t;
			}
			cout << a1*b1/b << endl;
		}
	} 
	return 0;
}
//int gcd(int a, int b) { 递归代码简介，思路清晰，欧几里得扩展 
//	if(b == 0) return a;   但是不如循环效率高 
//	return gcd(b,a%b);
//}



