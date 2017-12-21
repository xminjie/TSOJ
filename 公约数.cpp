#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int a, b, t;
	cin >> a >> b;
	if(a < b)
		swap(a,b); 
	while (a % b != 0) {
		t = a % b;
		a = b;
		b = t;
	}
	cout << b;
} 
