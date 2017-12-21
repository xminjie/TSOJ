#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int n; 
	while(cin >> n) {
		int a[9] = {0};
		if(n < 0) {
			a[1] = 1;
			n = -1 * n;
		}
		int j = 8;
		while(n) {
			a[j--] = n % 2;
			n = n / 2;
		}
		for(int i = 1; i <= 8; i++) {
			cout << a[i];
		}
		cout << endl;
	}
	return 0;
}

