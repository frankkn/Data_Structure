## [Graph Representation v1 Problem](http://adalab.cs.nthu.edu.tw/contest/48/problem/3-1)
### Description

Given an undirected graph G=(V,E), note that:

* G may not be connected.
* G doesn't have multiple edges and self-loops.

There are n vertices in V, denoted by 1,2,...,n.

Please answer two classes of queries:

* D u : Asking the degree of vertex u in graph G. Print the degree in a line.
* N u v : Asking if u, v are neighboring vertices in graph G. If yes, print a line "Y". Otherwise, print a line "N".

### Input
The first line contains three integers n, m and q — the size of V, the size of E and the number of queries.

Each of the following m lines contains two integers ui and vi (1 ≤ ui,vi ≤ n ; ui ≠ vi), being an edge in E.

In the following q lines, each line contains one query described above.

Restrictions:
* 2 <= n <= 1000
* 1 <= m <= n(n-1)/2
* 1 <= q <= 5000

### Output
Output the sorted array in one line.For each query, output one line.

### Sample Input

```
7 5 4
1 2
3 2
1 3
2 6
4 6
D 2
D 5
N 2 1
N 4 7
```

### Sample Output
```
3
0
Y
N
```