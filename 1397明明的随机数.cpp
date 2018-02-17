#include <iostream>
#include <set>
using namespace std;
int main() {
	set<int> s;
	int n, t ;
	while(cin >> n) {
		for(int i = 0; i < n; i++) {
			cin >> t;
			s.insert(t);
		}
		cout << s.size() << endl;
		for(auto i = s.begin() ; i != s.end() ;i++) { 
			if(i != s.begin() )	cout << ' ';
			cout << *i;
		}
		cout << endl;
		s.clear() ;
	}
	return 0;
}

