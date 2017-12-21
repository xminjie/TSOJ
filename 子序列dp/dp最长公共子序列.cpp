#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int s[100][100] = {0};
	int l1, l2; 
	string s1 = "123456789", s2 = "123468";
	s1 = '0' + s1;//辅助为了使下标从1开始 
	s2 = '0' + s2;
	l1 = s1.size() ; l2 = s2.size() ;
	for(int i = 1; i < l1; i++) {
		for(int j = 1; j < l2; j++) {
			if(s1[i] == s2[j]) {
				s[i][j] = s[i-1][j-1] + 1;
				}
			else {
				s[i][j] = max(s[i-1][j],s[i][j-1]);
			}
			if(i == 3 && j == 5) {
			}
			cout << s[i][j];
		}
		cout << endl;
	} 
	int ans = s[l1-1][l2-1];
	cout << ans << endl;
	int i = l1 - 1, j = l2 - 1;
	while(i && j) {
		if(s1[i] == s2[j]) {
			cout << s1[i] << ' ';	//回溯是倒序输出，为了清晰就倒着输出了，
								 	//如果需要正序，自己加代码就行 
			ans--;
			i--;
			j--;
		}
		else {
			if(s[i-1][j] > s[i][j-1]) {
				i--;
			}
			else {
				j--;
			}
		}
	} 
	return 0;
}
