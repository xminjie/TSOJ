#include<bits/stdc++.h>
using namespace std;
int a,b,p,q,n,m,len = 1,s[10010],temp[10010],f[10010][10010];

void highplus(int k)
{
	for(int i=1;i<=len;i++)
	 f[k][i] = a*f[k-1][i]+b*f[k-2][i];
	for(int i=1;i<=len;i++)
	 if(f[k][i]>=10)
	 {
	 	f[k][i+1] += f[k][i]/10;
	 	f[k][i] = f[k][i]%10;
	 	if(f[k][len+1]) len++;
	 }
}
int quitt(int k)
{
	for(int i=len;i>=1;i--)
	 if(f[s[k]][i]!=0)
	  return i;
}
int main()
{
	freopen("test.txt","r",stdin);
	while(cin>>b>>a>>p>>q)
	{
		len = 1;
		memset(temp,0,sizeof(temp));
		memset(s,0,sizeof(s));
		memset(f,0,sizeof(f));
		cin>>m;
		for(int i=0;i<m;i++)
		 {
		 	cin>>s[i];
		 	temp[i] = s[i];
		 }
		sort(temp,temp+m);
		//cout<<temp[m-1]<<endl;;
		f[1][1] = p;
		f[2][1] = q;
		for(int i=3;i<=temp[m-1];i++)
		 highplus(i);
		for(int i=0;i<m-1;i++)
		 {
		 	int k = quitt(i);
		 	//cout<<k<<endl;
		 	for(int j=k;j>=1;j--)
		      cout<<f[s[i]][j];
		    cout<<" ";
		 }
		if(m>1)
		{
		int k = quitt(m-1);
		for(int j=k;j>=1;j--)
		 cout<<f[s[m-1]][j];
		cout<<endl;
	    }
	}
	return 0;
}
