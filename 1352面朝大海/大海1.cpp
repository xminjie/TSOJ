#include <iostream>
#include <cstring>

int a[1000005];
using namespace std;
int main()
{
	int m, n, num1, num2, testnum1, testnum2;
	while (scanf("%d%d",&m,&n) != EOF) { 
	 	int sum = 0;
		memset(a,0,sizeof(a));
		for (int i = 1; i <= n; i++) {
			cin >> num1 >> num2;
			for (int j = num1; j <= num2; j++) {
				a[j]++;
			}
		}
		cin >> testnum1 >> testnum2;
		for (int i = testnum1; i <= testnum2; i++) 
			sum += a[i];
		cout << sum << endl;
	}
	return 0;

}

