#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int len, n, res;
	while(cin >> len >> n) {
		int  l = len , r = 0;
		int now;
		char c;
		for(int i = 1; i <= n; i++) {
			cin >> now >> c;
			if(c == 'R')
				l = min(l,now);
			if(c == 'L')
				r = max(r,now);
		}
		res = max(len-l,r);
		printf("The last ant will fall down in %d seconds.\n", res);
	} 
	return 0;
}


