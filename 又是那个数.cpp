#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int k, i ,t, j, tt;
    int n[100];
    cin >> k;
    t = k;
    while(k--) {
    	cin >> n[k];
    }
    for(i = 0; i < t; i++) {
    	tt = n[i];
    	while(tt != 1 && tt != 0) {
    		if(tt % 2 != 0) 	tt = 3 * tt + 1;
        	else				tt /= 2;
        	if(tt == 1) ;
        	else
        	for(j = 0; j < t; j++) {
        		if(tt == n[j] && j != i)	n[j] = 0;
			}
        }
        
    }
    sort(n, n + t, greater<int>());
    tt = 1;
	 for(i = 0; i < t; i++)
		 if(n[i] !=0)
		    {	
		   		 if(tt == 1) ;
		   		 else cout << " ";
		    	 cout << n[i] ;
		    	 tt = 0;
		    }
    
}
