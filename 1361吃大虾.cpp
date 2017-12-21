#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int n,count;
	while(cin >> n) {
		count = 0;
		while(n != 1) {
			if(n%2 == 0) {
				n = n / 2;
			}
			else {
				n = (n - 1) / 2;
				count++;
			}
		}
	cout << count+1 << endl;
	}
	return 0;
}

