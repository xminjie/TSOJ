#include <stdio.h>
#include <string.h>
#define MAXM 30     //最大M 询问次数
#define MAXN 10000  //最大N
#define MAXL 3000  //最长答案 9959
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MLEN (sizeof(int)*MAXL) //数组占用空间
#define I(x) ((i/4%2*2+(x))%4)  //循环数组

int answer[MAXM][MAXL];
int a[4], b[4], p, q, m, maxm, l, ll;
int query[MAXM];

int tempf[4][MAXL]; // 斐波那契滚动数组
int tempm[2][MAXL]; // 临时乘法

int empty; // tempf中空闲的数组

		   /*
		   //f3=af2+bf1 => a0, b0
		   //f4=af3+bf2=(a^2+b)f2+abf1 => a1, b1
		   f5=af4+bf3=(a^3+2ab)f2+(a^2b+b^2)f1 => a2, b2
		   f6=af5+bf4=(a^4+3a^2b+b^2)f2+(a^3b+2ab^2)f1 => a3, b3
		   */

		   //空间清零
void memclr(int addr[]) {
	memset(addr, 0, MLEN);
}

//输入
int input() {
	maxm = -1;
	if (scanf("%d %d %d %d", b, a, &p, &q) == EOF)
		return -1;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", query + i);
		if (maxm < query[i]) maxm = query[i];

	}



	//预处理，跳位计算，一般使用a[2]/b[2], a[3]/b[3]，少数情况下使用a[0]/b[0], a[1]/b[1]
	a[1] = a[0] * a[0] + b[0];
	b[1] = a[0] * b[0];
	a[2] = a[0] * a[0] * a[0] + 2 * a[0] * b[0];
	b[2] = a[0] * a[0] * b[0] + b[0] * b[0];
	a[3] = a[0] * a[0] * a[0] * a[0] + 3 * a[0] * a[0] * b[0] + b[0] * b[0];
	b[3] = a[0] * a[0] * a[0] * b[0] + 2 * a[0] * b[0] * b[0];

	//斐波那契的f0, f1
	tempf[2][0] = 1;
	tempf[2][1] = p;
	tempf[3][0] = 1;
	tempf[3][1] = q;
	// tempf[2], tempf[3] => tempf[0], tempf[1]
	return 0;
}

//高精度大数x乘小整数y
void multiply(int x[], int y, int ans[]) {
	for (int i = 1; i <= x[0]; i++) {
		ans[i] += y * x[i];
		ans[i + 1] = ans[i] / 10000;
		ans[i] %= 10000;
	}
	ans[0] = x[0];
	while (ans[ans[0] + 1]) {
		ans[0]++;
		ans[ans[0] + 1] = ans[ans[0]] / 10000;
		ans[ans[0]] %= 10000;
	}
}

//高精度大数x加高精度大数y
void add(int x[], int y[], int ans[]) {
	int l = MAX(x[0], y[0]);
	for (int i = 1; i <= l; i++) {
		ans[i] += x[i] + y[i];
		ans[i + 1] = ans[i] / 10000;
		ans[i] %= 10000;
	}
	ans[0] = l;
	if (ans[ans[0] + 1])
		ans[0]++;
}

//斐波那契数列f=ax+by
void f(int a, int x[], int b, int y[], int ans[]) {
	memclr(tempm[0]);
	memclr(tempm[1]);
	multiply(x, a, tempm[0]);
	multiply(y, b, tempm[1]);
	add(tempm[0], tempm[1], ans);
}

//把循环数组的答案保存到answer中
void save(int ia, int _if) {
	memcpy(answer[ia], tempf[_if], MLEN);
}

int main() {
	freopen("test.txt","r",stdin);
	while (1) {
		int ret = input();
		if (ret == -1)
			break;
		for (int i = 5; i <= maxm + 4; i += 4) {
			//每4位跳着计算
			for (int j = 0; j < m; j++) {
				//判断是否有询问的位置
				//假设已经计算97,98，现在的i为101
				//如果有问第97,98,99,100位的值是多少，在此处得到答案
				int delta = query[j] - (i - 4);
				//先计算97/98/99/100和97的差值
				//如果差是0/1，即问第97/98位是什么，答案已经保存在tempf中
				if (delta == 0 || delta == 1) {
					save(j, I(delta));
				}
				//如果差是2/3，即问第99/100位是什么，需要计算f99=bf97+af98=b[0]f97+a[0]f98
				//                              f100=bf98+af99=abf97+(a^2+b)f98=b[1]f97+a[1]f98
				else if (delta == 2 || delta == 3) {
					memclr(tempf[I(delta)]);
					f(b[delta - 2], tempf[I(0)], a[delta - 2], tempf[I(1)], tempf[I(delta)]);
					save(j, I(delta));
				}
			}
			memclr(tempf[I(2)]);
			memclr(tempf[I(3)]);
			f(b[2], tempf[I(0)], a[2], tempf[I(1)], tempf[I(2)]);   // fn+2=b[2]fn+1+a[2]fn
			f(b[3], tempf[I(0)], a[3], tempf[I(1)], tempf[I(3)]);   // fn+3=b[3]fn+1+a[3]fn
		}

		for (int i = 0; i < m; i++) {
			for (int j = answer[i][0]; j > 0; j--) {
				ll = answer[i][j];
				l = 0; 
				while (ll > 0) {
					ll /= 10;
					l++;
				}//判断位数补0 
				
				if (j != answer[i][0] && l < 4) {
					for (int k = 0; k < (4 - l); k++)
						printf("0");
				}
				if(answer[i][j] !=0 )	printf("%d", answer[i][j]);

				if (i != m - 1) printf(" ");
			}
		}
		printf("\n");
	}
}
