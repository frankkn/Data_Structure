## [Last in Preorder](http://adalab.cs.nthu.edu.tw/contest/48/problem/7-1)
### Description

You are given a rooted Binary Tree, please print the last element that appears in the preorder traversal.

Note
* Each vertex of the tree is labeled 1~n distinctly.

### Input

The first line is n: The number of vertices of the tree.

Then followed by n lines. Each line contains li, ri
​
li/ri denotes the left/right child of the ith vertex.

If the vertex has no left/right child, the coresponding ​li/ri will be -1.

Restrictions
* 1 ≤ n ≤ 10^6

### Output

Your output should be one line with one integer x.

x is the last element of the preorder traversal.

### Sample Input 1

```
5
-1 -1
-1 -1
-1 -1
3 2
4 1
```

### Sample Output 1

```
1
```

### Hint

The preoder of the tree is 5 4 3 2 1.The last element is 1.