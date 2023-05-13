## [Is DAG](http://adalab.cs.nthu.edu.tw/contest/48/problem/6-1)
### Description

In graph theory, a directed acyclic graph (DAG) is a directed graph with no directed cycles.

Given a directed graph G=(V,E), note that:
* For any two vertices u,v in V, there may not exists path from u to v.
* G doesn't have multiple edges and self-loops.

V is a set of n vertices, denoted by 1,2,...,n.

E is a set of m edges, and each edge is represented by two ordered vertices u,v, which denotes an edge from vertex 
u to vertex v.

Please answer if graph G is a directed acyclic graph (DAG) or not.

### Input

The first line contains two integers n and m — the size of V and the size of E.

Each of the following m lines contains two integers ui and vi​, being an edge in E.

Restrictions
* 2 ≤ n ≤ 10^5
* 1 ≤ m ≤ min( n(n−1)/2, 2×10^5 )
* 1 ≤ ui, vi ≤ n, ui != vi for 1 <= i <= m

### Output

For each testcase, output one line, which answer the number of connected components in graph G.

### Sample Input 1

```
5 4
2 3
3 4
2 4
5 1
```

### Sample Output 1

```
YES
```

### Sample Input 2

```
5 4
1 2
2 3
3 4
4 2
```

### Sample Output 2

```
NO
```