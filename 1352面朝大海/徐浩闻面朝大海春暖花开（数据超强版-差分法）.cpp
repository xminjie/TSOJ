# include<stdio.h>
int main()
{
	int N, M, T, L, R, i, j, count = 0, front = 0;
	int sum[10];
	while(scanf("%d %d %d", &N, &M, &T) != EOF) 
	{
		int Map[100005] = {0}, Sum[100005] = {0};
		for(i = 1; i <= M; i++)
		{
			scanf("%d %d", &L, &R);
			Map[L]++;             //从L块土地往后每块土地上种一朵花 
			Map[R+1]--;	         //从R+1块土地往后每块土地上拔掉一朵花 
		}
		for(i = 1; i <= N+1; i++)
		{
			front += Map[i];//计算从这块土地上往后每块土地上要种的花的数目
			Sum[i] = Sum[i-1] + front;// 计算从第一块土地到第i块土地之前（包括第i块土地）这些土地上种花的总数 	 
		}
		for(j = 0; j < T; j++)
		{
			scanf("%d %d", &L, &R);
			sum[j] = Sum[R] - Sum[L-1];//求在区间[L,R]这些土地上花的总数 
		 } 
		 for(j = 0; j < T; j++)
		 	printf("%d\n", sum[j]);
		 front = count = 0;
	}
	
 } 
