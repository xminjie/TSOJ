
1409:递增三元组 [ O(n³) 不给过版]
难度： 永恒钻石    时间限制： 3000MS   空间限制： 16MB   提交数： 142   通过数： 11 题目来源: admin
题目内容
[2018 蓝桥杯省赛 C\C++ B 组]
六. 递增三元组
问题描述
给定三个整数数组

A = [A1, A2, ..., AN],

B = [B1, B2, ..., BN],

C = [C1, C2, ..., CN],

请你统计有多少个三元组 (i, j, k) 满足:

1 <= i, j, k <= N 且

Ai < Bj < Ck

输入描述
有多组测试数据，对于每组测试数据：

第一行包含一个整数 N。

第二行包含 N 个整数 A1, A2, ..., AN。

第三行包含 N 个整数 B1, B2, ..., BN。

第四行包含 N 个整数 C1, C2, ..., CN。

在测试数据集中，有两组大规模测试数据集。

在大规模测试数据集中，N 的范围在 [9950, 10000) 之间。
                   
                   输出描述
                   对于每组测试数据，输出一行整数表示答案。
                   
                   样例输入
                   3
                   
                   1 1 1
                   
                   2 2 2
                   
                   3 3 3
                   
                   样例输出
                   27
                   
                   蓝桥杯原题数据规模 （非 TSOJ 此题的测试数据规模，下列数据 仅供参考 ）
                   对于 30% 的数据，1 <= N <= 100
                   
                   对于 60% 的数据，1 <= N <= 1000
                   
                   对于 100% 的数据，1 <= N <= 100000; 0 <= Ai, Bi, Ci <= 100000#include <iostream>
        哈希散列加查分，o(n)时间复杂度
#include <vector>
#include <cstring>
using namespace std;
long long  a[20010], c[20020];
int main() {
    int n;
    while (cin >> n) {
        long long t, sum = 0;
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        vector<long long> b(n);
        for(int i = 0; i < n; i++) {
            scanf("%lld",&t);
            a[t]++;
        }
        for(int i = 0; i < n; i++)
            scanf("%lld",&b[i]);
        for(int i = 0; i < n; i++) {
            scanf("%lld",&t);
            c[t]++;
        }
        for(int i = 0; i <= 20009; i++)
            a[i] = a[i] + a[i-1];
        for(int i = 20009; i >= 0; i--)
            c[i] = c[i+1] + c[i];
        for(int i = 0; i < n; i++)
            sum += a[b[i]-1] * c[b[i]+1];
        printf("%lld\n", sum);
    }
    return 0;
}
