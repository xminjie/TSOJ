1138:American Heritage
难度： 秩序白银    时间限制： 1000MS   空间限制： 16MB   提交数： 7   通过数： 2 题目来源: nuistoj
题目内容
题目描述:
Farmer John takes the heritage of his cows very seriously. He is not, however, a truly fine bookkeeper. He keeps his cow genealogies as binary trees and, instead of writing them in graphic form, he records them in the more linear tree in-order" and tree pre-order" notations.

Your job is to create the `tree post-order" notation of a cow"s heritage after being given the in-order and pre-order notations. Each cow name is encoded as a unique letter. (You may already know that you can frequently reconstruct a tree from any two of the ordered traversals.) Obviously, the trees will have no more than 26 nodes.

Here is a graphical representation of the tree used in the sample input and output:

              C
            /   
           /     
          B       G
         /      /
        A   D   H
           / 
          E   F

The in-order traversal of this tree prints the left sub-tree, the root, and the right sub-tree.

The pre-order traversal of this tree prints the root, the left sub-tree, and the right sub-tree.

The post-order traversal of this tree print the left sub-tree, the right sub-tree, and the root.

----------------------------------------------------------------------------------------------------------------------------
题目大意：
给出一棵二叉树的前序遍历(preorder)和中序遍历(inorder)，求它的后序遍历(postorder)。

你需要知道的：
1：二叉树的 相关定义可以在书上或者网上找到。

2：样例 输入输出反映的二叉树在上面。
输入描述：
Line 1:

The in-order representation of a tree.

Line 2:

The pre-order representation of that same tree.

输出描述：
A single line with the post-order representation of the tree.

样例输入:
ABEDFCHG

CBADEFGH

样例输出:
AEFDBHGC
#include <iostream>
#include <algorithm>
using namespace std;
string in, pre;
void f(int root, int be, int end) {
	if(end < be)	return ;
	int i = be;
	while(in[i] != pre[root])	i++;
	f(root+1,be,i-1);
	f(root+1+i-be,i+1,end);
	cout << in[i];
	return ;
}
int main() {
	cin >> in >> pre;
	f(0,0,in.size()-1);
	return 0;
}
