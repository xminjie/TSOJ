#include <iostream>//1.字符串存储，2.模拟手动计算 3.不必递推每一项 4.代码要清晰 
#include <string>
using namespace std;
#define N 10001
string s[N];
string mul(string s1,int n) {//手动模拟乘法，进位计算 
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

string add(string s1, string s2) {
	string st = s1;
	char c;
	int jin = 0;
	if(s1.size() > s2.size() ) {//提前处理s1.s2位数不一样,(只会出现s1>=s2的情况)因为s1是后一项， 
		for(int i = 0; i < s1.size() - s2.size();i++) {//空的位置补0 ,例如888 66 -> 888 066; 
			st[i] = '0';
		}
		for(int i = s1.size() - s2.size(),j = 0; i < s1.size() ; i++,j++)	{
			st[i] = s2[j];
		}
		s2 = st;
	}
	for(int i =  s2.size() - 1; i >= 0; i--)	{//手动模拟，进位计算
		st[i] = ((s1[i] + s2[i] - '0' - '0' + jin) % 10) + '0';
		jin = (s1[i] + s2[i] - '0' - '0' + jin) / 10;
	}
	c = jin + '0';//如果乘后多出来一位
	if(jin >= 1) {
		st = c + st;
	}
	return st;
	
}

string fun(string s1, string s2, int n1, int n2) {
	s1 = mul(s1,n1);
	s2 = mul(s2,n2);
	return add(s1,s2);
}
int main() {
	int a, b, m, n,t;
	string p, q;
	//freopen("test.txt","r",stdin);
	while(scanf("%d%d",&a,&b) != EOF) {
		cin >> p >> q;//1.用字符串存每一项 （数太大int ，long long也会炸） 
		scanf("%d",&m);
		s[1] = p;
		s[2] = q;
		int ar[m+1];
		for(int i = 1; i <= m; i++) {
			scanf("%d",&ar[i]);
		}
		t = ar[1];	
		for(int i = 2; i <= m; i++) {//需要用到第几项，就计算到第几项 
			if(t < ar[i])
				t = ar[i]; 
		}
		for(int i = 3; i <= t; i++) {
			s[i] = fun(s[i-1],s[i-2],b,a);//每一项递推 
		}
		for(int i = 1; i <= m-1; i++) {
			cout << s[ar[i]] << ' '; 
		}
		cout << s[ar[m]] << endl;
	}
	return 0;
}
/*得一提的是；代码要清晰；
之前 fun(s[i-1],s[i-2],b,a)直接写在一个函数里，
虽然不能算错，但是很乱，后期调试或者阅读代码很不方便 
之前写在一个大函数里总是调试特费劲，自己代码都看到累 
拆成几个小函数，很清晰；*/ 
