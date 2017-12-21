#include <iostream>
using namespace std;
int main()
{
	int n, m, t, n1, n2;
	while (scanf("%d%d%d",&n,&m,&t) != EOF) { 
		int map[100005] = {0};
		for (int i = 1; i <= m; i++) {
			scanf("%d%d",&n1,&n2);
			map[n1]++;
			map[n2+1]--;
		}
		for(int i = 2; i<= n+1; i++) {
			map[i] += map[i-1];
			map[i-1] += map[i-2];
		}
		
		for(int i = 1; i <= t; i++) {
			scanf("%d%d",&n1,&n2);
			cout << map[n2] - map[n1-1] << endl;
		} 
	}
	return 0;
}
