#include <iostream> 
#include <string>
#include <algorithm>
using namespace std;
int f(int n) {
	 	if(n == 1 || n == 2)
	 		return n;
	 	else
	 		return(f(n - 1) + f(n - 2)) ; 
	 }	

int main()
{
  
	int n;
	while(scanf("%d", &n) != EOF)
	cout << f(n) << endl;
	
  
}
