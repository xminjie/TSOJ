1363:类斐波那契数列
难度： 尊贵铂金    时间限制： 1000MS   空间限制： 64MB   提交数： 242   通过数： 8 题目来源: admin
题目内容
[2017 江苏科技大学 程序设计竞赛]
C. 类斐波那契数列 (改编)
题目描述
在组合数学中，有一个很著名的递推公式，称为斐波那契递推公式，它具有许多优美的数学性质，乃至于美国数学学会为它单独发行过数学期刊。通常，我们用 F(n) 表示一个类斐波那契数列的第 n 项。它的计算公式是：

       ╭  a * F(n - 2) + b * F(n - 1) (n > 2)
F(n) = |  p (n = 1)
       ╰  q (n = 2)
其中，a, b, p, q, 均为待确定的常数

现在想请问你某个类斐波那契数列的第 i 项是多少。

输入描述
有多组测试数据，每组测试数据占三行。

在第一行中，有一组空格分隔的正整数 a, b, p, q, 用以确定类斐波那契数列的递推公式

在第二行中，有一个整数 m，表示在这组测试数据中，需要计算 m 次 F(n)。

在第三行中，有 m 个用空格分隔的正整数 n1, n2, n3, ... , nm, 表示需要计算的某项的下标。

a, b, p, q 均不超过 10。

m 不超过 25。

每个 n 均不超过 10000。

输出描述
对每组测试数据，输出一行答案，多个计算结果间用空格分隔。

输出中不要有任何多余的空格。

输入样例
1 1 1 1

3

5 10 98

1 2 5 10

3

5 8 10

输出样例
5 55 135301852344706746049

145 2040 11890
#include <iostream>//1.字符串存储，2.模拟手动计算 3.不必递推每一项 4.代码要清晰 
#include <string>
using namespace std;
#define N 10001
string s[N];
string mul(string &s1,int &n) {//手动模拟乘法，进位计算 
	int jin = 0;
	char c;
	string st = s1;
	for(int i = s1.size() - 1; i >= 0; i--) {
		st[i] = ((s1[i] - '0') * n + jin) % 10 + '0';
		jin = ((s1[i] - '0') * n + jin) / 10;
	}
	c = jin + '0';//如果乘后多出来一位 
	if(jin >= 1)
		st = c + st;
	return st;
}

string add(string &s1, string &s2) {
	string st = s1;
	char c;
	int jin = 0, i, j;
	if(s1.size() > s2.size() ) {//提前处理s1.s2位数不一样,(只会出现s1>=s2的情况)因为s1是后一项， 
		for(i = 0; i < s1.size() - s2.size();i++) //空的位置补0 ,例如888 66 -> 888 066; 
			st[i] = '0';
		for(i = s1.size() - s2.size(),j = 0; i < s1.size() ; i++,j++)	
			st[i] = s2[j];
		s2 = st;
	}
	for(i =  s2.size() - 1; i >= 0; i--)	{//手动模拟，进位计算
		st[i] = ((s1[i] + s2[i] - '0' - '0' + jin) % 10) + '0';
		jin = (s1[i] + s2[i] - '0' - '0' + jin) / 10;
	}
	c = jin + '0';//如果加后多出来一位
	if(jin >= 1) 	st = c + st;
	return st;
}
string fun(string &s1, string &s2, int n1, int n2) {
	string s11,s22;
	s11 = mul(s1,n1);
	s22 = mul(s2,n2);
	return add(s11,s22);
}
int main() {
	int a, b, m, n, t, i;
	while(scanf("%d%d",&a,&b) != EOF) {
		cin >> s[1] >> s[2];//1.用字符串存每一项 （数太大int ，long long也会炸） 
		scanf("%d",&m);
		int ar[m+1];
		t = 0; 
		for( i = 1; i <= m; i++) {//t的意义，需要用到第几项，就计算到第几项
			scanf("%d",&ar[i]);
			if(t < ar[i])
				t = ar[i]; 
		}
		for( i = 3; i <= t; i++) 
			s[i] = fun(s[i-1],s[i-2],b,a);//每一项递推 
		for( i = 1; i <= m-1; i++) //输出 //每行最后一个数后不留空格； 
			cout << s[ar[i]] << ' '; 
		cout << s[ar[m]] << endl; 
	}
	return 0;
} 
/*得一提的是；代码要清晰；
之前 fun(s[i-1],s[i-2],b,a)直接写在一个函数里，
虽然不能算错，但是很乱，后期调试或者阅读代码很不方便 
之前写在一个大函数里总是调试特费劲，自己代码都看到累 
拆成几个小函数，很清晰；*/ 
