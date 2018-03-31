题目描述:
修罗王与邪狼被关进监狱，该监狱的地下秩序实际上被不少黑暗势力所把持，这些黑暗势力根据其实力不同，划分出了大大小小的势力范围。具体为：监狱是一个给定的矩形，每一个黑暗势力的势力范围都必须是一个正方形，划分时，最大的黑暗势力尽可能多地从矩形中划一块正方形，接下来是第二大的黑暗势力在剩下的矩形中尽可能多地划分出一块正方形……

输入描述：
多组输入，每组两个整型数，表示矩形的长和宽

输出描述：
对应于每组数据，划分的正方形的个数

样例输入:
3 4

样例输出:
4
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int cnt = 0;
void f(int a, int b) {
	cnt++;
	if(a == 1  && b == 1) return ;
	else	f(min(a,b),abs(a-b));
}
int main() {
	int a, b;
	while(cin >> a >> b) {
		if(a == b) {
			cout << 1 << endl;
			continue;
		}
		cnt = 0;
		f(a,b);
		cout << cnt << endl;
	}
return 0;
}

