#include <cstring> 
#include <iostream> 
using namespace std;
int a[100005][2];
int main() {
	int n, m;
	while(scanf("%d%d",&n,&m) != EOF ) {

		for(int i = 0; i < m; i++) {
			scanf("%d%d",&a[i][0],&a[i][1]);
		}
		int b, c, count = 0;
		scanf("%d%d",&b,&c);
		for(int i = 0; i < m; i++) {
			if((a[i][0] <= c && a[i][1] >= b) ) 
				count += min(c,a[i][1]) - max(a[i][0],b) +1;
		}
		cout << count << endl;
	}
	
}
