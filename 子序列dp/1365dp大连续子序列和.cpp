#include <iostream>
#include <algorithm>
int a[95005];
int sum[95005];
using namespace std;
int MaxSum(int n)
{
    sum[0] = a[0];
    int t = a[0];
    for(int i = 1; i < n; i++) 
    {	
    	//sum[i]表示以a[i]为子串尾时，最大的子序列的和 ； 
		//如果在sum[i-1]<0;说明之前的数不会计入序列；那此时，就要重新开始计数，于是新sum[i] = a[i];
		//如果在sum[i-1]>=0;说明之前的数会计入序列；那此时继续向后；
		if(sum[i-1] >= 0) 			 
			sum[i] = sum[i-1] + a[i];
		else
			sum[i] = a[i];
		if(t < sum[i]) 
			t = sum[i];
    }
	return t;
	
}
int main() {
//	freopen("test.txt","r",stdin);
	int n;
	while(cin >> n) {
		for(int i = 0; i < n; i++) {
			scanf("%d",&a[i]);
		}
		cout << MaxSum(n) << endl;
	}
	return 0;
}


