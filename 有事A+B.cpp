#include <iostream> 
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string a, b;
	int c[10000];
	int i, j, jin, count = 0;
	cin >> a >> b ;
	if(a.size() > b.size())
		swap(a,b);
	jin = 0;
	for (i = a.size() - 1, j = b.size() - 1; i >=0, j >= 0; i--, j-- ) {
		c[count++] = (a[i] -'0' + b[i] -'0' + jin) % 10;
		jin = (a[i] -'0' + b[i] -'0' + jin) / 10;
	}
	if(a.size() == b.size()  && jin != 0)
			c[count++] = jin;
	else{
		for(; j >= 0; j--) {
			c[count++] = (b[i] -'0' + jin) % 10;
			jin = (b[i] -'0' + jin) / 10;
		}
	if( jin != 0)
		c[count++] = jin;
	}
	for(i = count - 1; i >= 0;  i--)
		cout << c[i];
}
