#include <iostream>
#include <algorithm>
#include <string>
int a[95005];
int sum[65005];
using namespace std;
int main() {
	int N; 
	while (scanf("%d",&N) != EOF) {
		a[0] = 0, sum[0] = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d",&a[i]);
			sum[i] = a[i] + sum[i-1]; 
		}
		int t = a[1];
		for(int i = 1; i <= N; i++) {//多少个数最大 
			for(int j = 1; j+i-1 <= N; j++) {
				if(t < sum[j+i-1] - sum[j-1])
					t = sum[j+i-1] - sum[j-1];
			}
		}
		cout << t << endl;
	} 
	return 0;
}

