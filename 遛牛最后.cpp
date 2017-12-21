#include <iostream>
#include <cstring>
using namespace std;
int count = 0,bx, by, ex, ey;
int m,n;
int x[4]= {1,-1,0,0}, y[4]= {0,0,1,-1};
int map[100][100], isgo[100][100];
int dfs(int tx,int ty) {
	if(tx == ex && ty == ey)
		{
			count++;
		}
	else for(int i = 0; i < 4; i++)
			if(tx+x[i]>=1&&tx+x[i]<=m&&ty+y[i]>=1&&ty+y[i]<=n&&map[tx+x[i]][ty+y[i]] == 1 && isgo[tx+x[i]][ty+y[i]] == false)
			{
				isgo[tx+x[i]][ty+y[i]] = true;
				dfs(tx+x[i],ty+y[i] );
				isgo[tx+x[i]][ty+y[i]] = false;
			}
	}
int main() {
	freopen("d://test.txt","r",stdin);
	char c;
	while(cin>>m)
	{
		count  = 0;
		memset(map,0,sizeof(map));
		memset(isgo,0,sizeof(isgo));
		cin>>n;
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				cin >> c;
			
			if(c == '0') 
				{
					map[i][j] = 0;
				}
			else
				{
					map[i][j] = 1;
					if(c == 'S')
						{
							bx = i;
							by = j;
							isgo[i][j] = true; 
						}
					if(c == 'E')
						{
							ex = i;
							ey = j;
						}
				}
				
			}
		}
		dfs(bx,by);
		if(count==0) {
			cout<<"-1";
			continue;
		}
		cout << count << endl; 
    }
		return 0; 
} 
