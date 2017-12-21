#include <iostream>//本题刚学的分值递归 
#include <algorithm>
using namespace std;
	//分治算法 
int a[95005];
int f(int left,int center, int right) {
	//求包含左半部分最右元素的最大和 
        int s1 = a[left];
        int lefts = 0;
        for(int i = center; i >= left; i--)
        {
            lefts += a[i];
            if(lefts > s1) 
				s1 = lefts;
        }
        //求包含右半部分最左元素的最大和 
        int s2 = a[center+1];
        int rights = 0;
        for(int i = center+1; i <= right; i++)
        {
            rights += a[i];
            if(rights > s2) 
			s2 = rights;
        }
        return s1 + s2;
}
int maxsubsum(int left,int right)
{
    int sum = 0;
    if(left == right)//基本情况：只有一个元素 
        sum = a[left];
    else
    {
        int center = (left+right)/2;
        int leftsum = maxsubsum(left,center);//左半部分 
        int rightsum = maxsubsum(center+1,right);//右半部分
        int centersum  = f(left,center,right);//左边最右之和最大+右边最左之和最大 
		sum = max(centersum,max(leftsum,rightsum));
    }
    return sum;
}
int main() {
	freopen("test.txt","r",stdin);
	int n;
	while(cin >> n) {
		for(int i = 0; i < n; i++) {
			scanf("%d",&a[i]);
		} 
		cout << maxsubsum(0,n-1) << endl;
		}
	return 0;
}

