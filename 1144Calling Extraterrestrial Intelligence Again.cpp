1144Calling Extraterrestrial Intelligence Again
难度： 秩序白银    时间限制： 1000MS   空间限制： 16MB   提交数： 2   通过数： 2 题目来源: nuistoj
题目内容
题目描述:
A message from humans to extraterrestrial intelligence was sent through the Arecibo radio telescope in Puerto Rico on the afternoon of Saturday November 16, 1974. The message consisted of 1679 bits and was meant to be translated to a rectangular picture with 23 73 pixels. Since both 23 and 73 are prime numbers, 23 73 is the unique possible size of the translated rectangular picture each edge of which is longer than 1 pixel. Of course, there was no guarantee that the receivers would try to translate the message to a rectangular picture. Even if they would, they might put the pixels into the rectangle incorrectly. The senders of the Arecibo message were optimistic.

We are planning a similar project. Your task in the project is to find the most suitable width and height of the translated rectangular picture. The term "most suitable" is defined as follows. An integer m greater than 4 is given. A positive fraction a / b less than or equal to 1 is also given. The area of the picture should not be greater than m. Both of the width and the height of the translated picture should be prime numbers. The ratio of the width to the height should not be less than a / b nor greater than 1. You should maximize the area of the picture under these constraints.

In other words, you will receive an integer m and a fraction a / b. It holds that m > 4 and 0 < a / b < 1. You should find the pair of prime numbers p, q such that pq <= m and a / b <= p / q <= 1, and furthermore, the product pq takes the maximum value among such pairs of two prime numbers. You should report p and q as the "most suitable" width and height of the translated picture.

输入描述：
The input is a sequence of at most 2000 triplets of positive integers, delimited by a space character in between. Each line contains a single triplet. The sequence is followed by a triplet of zeros, 0 0 0, which indicated the end of the input and should not be treated as data to be processed.

The integers of each input triplet are the integer m, the numerator a, and the denominator b described above, in this order. You may assume 4 < m <= 100000 and 1 <= a <= b <= 1000.

输出描述：
The output is a sequence of pairs of positive integers. The i-th output pair corresponds to the i-th input triplet. The integers of each output pair are the width p and the height q described above, in this order.

Each output line contains a single pair. A space character is put between the integers as a delimiter. No other characters should appear in the output.

样例输入:
5 1 2

99999 999 999

1680 5 16

1970 1 1

2002 4 11

0 0 0

样例输出:
2 2

313 313

23 73

43 43

37 53
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int iss(int n) {
	if(n == 2 || n == 3)	return true;
	for(int i = 2; i*i <= n; i++)
		if(n % i == 0)	return false;
	return true;
}
int main() {
	int a, b, c, a1, b1, c1;
	int is[1001] = {0};
	for(int i = 1; i < 1001; i++)
		if(iss(i))	v.push_back(i);
	while(cin >> a >> b >> c) {
		int maxn = 0, ii, jj;
		if( !a && !b && !c)	return 0;
		for(int i = 0; v[i] <= a; i++) {
			for(int j = 0; v[j] <= a; j++) {
				if(v[i]*v[j] <= a && v[i] <= v[j] && b * v[j] <= v[i] * c) {
					if(v[i] + v[j] > maxn) {
						ii = v[i];
						jj = v[j];
						maxn = v[i] + v[j];
					}
				}
			}
		}
		cout << ii << ' ' <<  jj << endl;
	}
	return 0;
}
