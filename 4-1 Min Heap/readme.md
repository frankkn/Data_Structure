## [Min Heap](http://adalab.cs.nthu.edu.tw/contest/48/problem/4-1)
### Description

Please implement a binary min heap that supports the following operations:

* 1 x: Insert number x
* 2: Remove an element with smallest value in the heap. If the heap is already empty, ignore this command.
* 3: Report the smallest number in the heap. If the heap is already empty, print "EMPTY" (without quotation mark).

### Input

The first line contains an integer q, being the number of operations.

The following q lines are the operations described in the problem statements.

Restrictions:
* 1 <= q <= 2*10^6
* -10^9 <= x <= 10^9

### Output
For each query with type 3, print the answer in one line.

### Sample Input

```
11
1 8
1 7
3
1 4
3
2
2
3
2
2
3
```

### Sample Output
```
7
4
8
EMPTY
```