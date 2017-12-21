#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[700005] ; 
bool is(int n) {
	int count = 0;
	if(n < 5)
		return false;
	else {
		int i;
		for( i = 2; i*i <= n; i++) {
			if(n%i == 0)
				count++;
			if(count == 2)
				return false;
		}
		if(count == 1 && (i-1)*(i-1) != n)
		return true;
		else
		return false;	
	}
}
int main() {
	memset(a,0,sizeof(a));
	for(int i = 1; i <= 700005; i++) {
			if(is(i) == true)
			a[i] = 1;
			a[i] += a[i-1] ;//用sum[]来计数更清晰，我为减少内存占用就顺接着便用a[]，不影响的； 
		}
	int m, n;
	while(cin >> m >> n) {
		cout << a[n] - a[m-1] << endl;
	}
	return 0;
}

/*1.	每个四因子数n，四因子为1, a, n/a ,n;组成;
	只要在i*i <= n;前判断只要存在一个a就行了(n/a 一定存在); (注意如果 a == n/a; 这就重复不能算了; ) 
	所以，既要满足只有一个，而且还不能i*i==n; 
2.	如果判断出有2个a;那么一定不符合，可以直接break; */
 

