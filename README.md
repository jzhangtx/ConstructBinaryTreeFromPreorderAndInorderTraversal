Construct Binary Tree from Preorder and Inorder Traversal (Please refer to the docx version of README for better understanding)


Given the preorder and inorder traversals of a binary tree, construct and return the binary tree.

Example
preorder-inorder
Testing
Input Format
The first line contains an integer T denoting the number of test cases.

For each test case, the input has 3 lines:

The first line contains an integer n denoting the length of the arrays.
The second line contains n space-separated integers denoting the preorder traversal of the binary tree.
The third line contains n space-separated integers denoting the inorder traversal of the binary tree.
Output Format
For each test case, the output has a line containing the level order traversal of the tree.

Sample Input
5
8
1 2 4 5 7 3 6 8
4 2 7 5 1 8 6 3
5
1 2 4 5 6
5 4 6 2 1
5
8 9 10 11 12
8 9 11 10 12
4
28 14 48 11
14 48 28 11
1
6
6
Expected Output
1 2 3 4 5 6 7 8
1 2 4 5 6
8 9 10 11 12
28 14 11 48
6