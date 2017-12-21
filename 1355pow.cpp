#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	string s;
	while(cin >> s) {
		int t;
		int  a, b = 0;
		for(int j = 0; j < s.size(); j++) {
			if(s[j] == ',') {
				t = j;
				break;
			}
		}
		a = s[t-1] - '0';
		if(s.size()-1 - t-1 == 1)
			b = s[s.size()-2] -'0';
		else {
				b= (s[s.size()-3] -'0')*10 + s[s.size()-2] -'0';		
				if(b == 0)
					b = 4;		
			}
		if(b == 0) 	
			cout << 1 << endl;
		else {
				cout << (int)pow(a,(b%4)+4)%10 << endl;
			} 
	}
}

