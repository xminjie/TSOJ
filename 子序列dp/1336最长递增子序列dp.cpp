#include <iostream>
#include <algorithm>
#include <cstring>
int a[50005]; 
int sum[50005];
using namespace std;
int main() {
	int n, t;
	while(scanf("%d",&n) != EOF) {
		for(int i = 0; i < n; i++) {
			scanf("%d",&a[i]);
			sum[i] = 1;
		}
		t = 1;
//		for(int i = 2; i < n; i++) {//dp
//			if(a[i] > a[i-1]) {
//				sum[i] += sum[i-1];
//				if(t < sum[i])
//					t = sum[i];
//			}
//		}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(a[j] < a[i])
				sum[i] = max(sum[j]+1,sum[i]);//判断是本来大还是，加入一个新的后大 
		if(t < sum[i]) 
			t = sum[i];
//			cout << sum[i] << ' ';
		}
//		cout << endl;
	}
		cout << t << endl;
	}
	return 0;
}


