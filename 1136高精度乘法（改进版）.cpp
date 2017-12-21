#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string mul(string s1, int i, int n) {
	string st = s1;
	int jin = 0;
	for(int j = s1.size() - 1; j >= 0; j--) {
		st[j] = (jin + (s1[j]-'0') * n) % 10 + '0';
		jin = (jin + (s1[j]-'0') * n )/ 10;
	}
	if(jin > 0) {
		char c = jin + '0';
		st = c + st;
	}
	for(int j = 1; j <= i; j++) {
		st =  st + '0';
	}
//	cout << st << endl;
	return st;
}
string plu(string s1, string s2) {
	if(s1.size()  < s2.size() ) {
		swap(s1,s2);
	}
	string st = s1;
	int d = s1.size() - s2.size() ;
	for(int i = 1; i <= d; i++) {
		s2 = '0' + s2;
	}
//	cout << endl << s1 << endl << s2 << endl;
	int jin = 0;
	for(int i =  s2.size() - 1; i >= 0; i--)	{//手动模拟，进位计算
		st[i] = ((s1[i] + s2[i] - '0' - '0' + jin) % 10) + '0';
		jin = (s1[i] + s2[i] - '0' - '0' + jin) / 10;
	}
	char c = jin + '0';//如果加后多出来一位
	if(jin >= 1) {
		st = c + st;
	}
//		cout << st << endl;
	return st;
}
int main() {
	string sa,sb,sres,ssub;
	while (cin >> sa >> sb) {
		sres = "0";
		int la, lb;
		la = sa.size() ;
		lb = sb.size() ;
		for(int i = lb - 1 ; i >= 0; i-- ) {
			ssub = mul(sa,lb-i-1,sb[i]-'0');
			sres = plu(sres,ssub);
		}
		cout << sres;
	} 
	return 0;
}


