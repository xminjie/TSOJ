#include <iostream> 
#include <string>
using namespace std;
int main() {
	string a, b;
	int i, j, t, jin, la, lb;
	cin >> a >> b;
	la = a.length();
	lb = b.length();
	int c[100][100];
	t = 0;
	for( i = lb - 1; i >= 0; i--) {
		t = lb - i -1;
		jin = 0;
		for(j = la - 1; j >=0; j--) {
			c[lb - i -1][t++] = ((b[i] - '0') * (a[j] -'0' ) + jin)% 10;
			jin = (b[i] - '0') * (a[j] -'0') /10;
		}
		c[lb - i -1][t] = jin ;

	}
	jin = 0;
	for(j = 0; j < la + lb; j++) {
		c[lb][j] = 0;
		for(i = 0; i < lb; i++) {
			c[lb][j] += c[i][j];
		}
		t = (c[lb][j] + jin) /10 ;
		c[lb][j] = (c[lb][j] + jin) % 10;
		jin = t;
 	}
 	for(i = 0; i < lb; i++) {
		for(j = 0; j < la + lb ;j++) {
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
 	for(i = la + lb -1; i >= 0; i-- ) {
 		if(i == la + lb -1 && c[lb][i] == 0)
 		;
 		else 
		cout << c[lb][i] ;
 		
	 }

}
