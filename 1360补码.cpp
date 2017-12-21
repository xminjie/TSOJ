#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int n; 
	while(cin >> n) {
		int a[9] = {0};
		int tt = n;
		if(n < 0) {
			a[1] = 1;
			n = -1 * n;
		}
		int j = 8;
		while(n) {
			a[j--] = n % 2;
			n = n / 2;
		}
		if(a[1] == 1) {
			for(int i = 2; i <= 8; i++) {
				if(a[i] == 0)
					a[i] = 1;
				else
					a[i] = 0;
			}
			int jin  = 0,t;
			int b[9] = {0};
			b[8] = 1;
			for(int i = 8; i >= 1; i--) {
				t = a[i]; 
				a[i] = (a[i] + b[i] + jin ) % 2;
				jin =  (t + b[i] + jin ) / 2;
			}
			if(tt == -128)
				a[1] = 1;
		}
		for(int i = 1; i <= 8; i++) {
			cout << a[i];
		}
		cout << endl;
	}
	return 0;
}

