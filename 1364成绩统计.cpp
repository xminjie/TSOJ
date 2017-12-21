#include <iostream>
#include <algorithm>
#include <string>
struct stu {
	int sco;
	int num;
}a[1000001],aa[1000001]; 
using namespace std;
int comp(stu a, stu b) {
	if(a.sco < b.sco )
		return 1;
	else
		return 0;
}
int main() {
	//freopen("test.txt","r",stdin); 
	int N;
	while (cin >> N) {
		for(int i = 0; i < N; i++) {
			cin >> a[i].sco;
			a[i].num = 1;//意思是你这个数据我要用 
		}
		for(int i = 0; i < N; i++) {//对所有数据进行合并去重 
			if(a[i].sco != -1) {
				for(int j = i+1; j < N; j++) {
					if(a[i].sco == a[j].sco) {
						a[i].num++;
						a[j].sco = -1;//意思是你这个数据我不用了以后， 扔了 
					}
				}
			}
		}
		int t;
		for(int i = 0,j = 0; i < N; i++) {//筛选出标尺数据 
			if(a[i].sco != -1) {
				aa[j].num = a[i].num;
				aa[j].sco = a[i].sco;
				j++;
				t = j;
	
			}
		}
		sort(aa,aa+t,comp);
		for(int i = 0; i < t; i++) {
			cout << aa[i].sco << " " <<  aa[i].num << endl;
		}
	} 
	return 0;
}
/*1.sort 超时
2.学生成绩作为下标，数组里存取到次成绩的人数；
		测试数据中可能会有100000000分的这种同学；内存爆，且runtime error；（毕竟魔法学院） 
3.不能用分数做下标，还想同时存，成绩和人数；
		快快用结构体；
4每个同学用都有自己的分数，并且取到改分数的人为1；
	那么接下来就是把同分数的数据合并去重了；
		遍历每个学生；if某同学是第一个考了该分的，那他就幸运了；
		他作为留下来的那个，不妨叫他标尺数据！！！；
		和他同分的并入他这个标尺；把并入的同学num设为-1；标记一下，
		意思是你这组数据可丢掉了，没用了；
	接下来，就只有num>=1 和num == -1 ； 数据了；
	筛选出来，快排，这下轻松多了
	这题算法复杂度感觉不是n2；因为好多废弃数据不会再作为标尺数据了；*/ 
