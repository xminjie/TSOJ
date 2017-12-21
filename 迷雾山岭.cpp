#include <iostream> 
using namespace std;
int main() {
	int a[100000],n, i, j, count = 0,res = 1, is;
	cin >> n;
	while(n--) {
		count = 0;
		res = 1;
		while(1) {
			cin >> a[count++]; 
			if(a[count - 1] == -1)
				break;
		} 
		count--;
		for(i = 1; i < count; i++){
			for(j = 0; j < i ; j++) {
				if(a[i] > a[j] )
				 {
				 		is = 1;
				 }
				else
				{
						is = 0;
						break;
					}
			}
			if(is == 1)
				res++;
		}
		cout << res << endl;
	}
}

