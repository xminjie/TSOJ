#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int main() {
	string s;
	int cnt;
	int m[200];
	while(getline(cin,s)) {
		memset(m,0,sizeof(m));
		cnt = 0;
		for(int i = 0; i < s.size(); i++)
			m[s[i]]++;
		for(int i = 0; i < s.size() ; i++)
			if(m[s[i]] == 1) {
				cnt++; 
				cout << s[i];
			}
		if(cnt == 0)	cout << -1;
		cout << endl;
	}
	return 0;
}

