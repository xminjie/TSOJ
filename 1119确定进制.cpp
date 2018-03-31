1119确定进制
难度： 秩序白银    时间限制： 1000MS   空间限制： 16MB   提交数： 20   通过数： 9 题目来源: nuistoj
题目内容
题目描述:
6 × 9 = 42 对于十进制来说是错误的，但是对于 13 进制来说是正确的。即，6(13) × 9(13) = 42(13)， 而 42(13) = 4 × 13 + 2 = 54(10)。

你的任务是写一段程序读入三个整数 p, q 和 r，然后确定一个进制 B (2 <= B <= 16) 使得 p × q = r。如果 B 有很多选择，输出最小的一个。

例如：当 p = 11, q = 11, r = 121 时，则有 11(3) × 11(3) = 121(3)。因为 11(3) = 1 × 31 + 1 × 30 = 4(10) 且 121(3) = 1 × 32 + 2 × 31 + 1 × 30 = 16(10)。对于进制 10，有 11(10) × 11(10) = 121(10)。这种情况下，应该输出 3。如果没有合适的进制，则输出 0。

输入描述：
输入有 T 组测试样例。T 在第一行给出。每一组测试样例占一行，包含三个整数 p, q, r。 p, q, r 的所有位都是数字，并且 1 <= p, q, r <= 1,000,000。

输出描述：
对于每个测试样例输出一行。该行包含一个整数，即使得 p × q = r 成立的最小的 B。如果没有合适的 B，则输出 0。

样例输入:
3

6 9 42

11 11 121

2 2 2

样例输出:
13

3

0
#include <iostream>
#include <algorithm>
using namespace std;
int maxn;
int f(int n, int k) {
	int ans = 0, cnt = 1;
	while(n) {
		maxn = max(maxn, n%10);
		ans += (n%10) * cnt;
		cnt *= k;
		n = n / 10;
	}
	return ans;
}
int main() {
	int n, a, b, c, flag; 
	cin >> n;
	for(int j = 0; j < n; j++) {
		maxn = flag = 0;
		cin >>  a >> b >> c;
		for(int i = 2; i <= 16; i++) {
			if(f(a,i) * f(b,i) == f(c,i)) {
				if(maxn >= i)	continue;
				cout << i << endl;
				flag = 1;
				break;
			}
		}
		if(flag == 0) 	cout << 0 << endl;
	} 
	return 0;
}
