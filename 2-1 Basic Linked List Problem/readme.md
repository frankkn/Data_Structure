## [Basic Linked List Problem](http://adalab.cs.nthu.edu.tw/contest/48/problem/2-1)
### Description

Maintain a linked list, which supports the following operations:

* IH i : Insert head. Insert a new node with integer i to the head of the linked list.

* IT i : Insert tail. Insert a new node with integer i to the tail of the linked list.

* RH : Remove head. Remove the node at the head of the linked list. (If the linked list is empty, don't do anything.)

* RT : Remove tail. Remove the node at the tail of the linked list. (If the linked list is empty, don't do anything.)

* S i : Search. Traverse the linked list and find if there exists a node with integer i. If yes, print a line "Y". Otherwise, print a line "N". (If the linked list is empty, print a line "E".)

* O : Output. Traverse the linked list from head to tail. Print the integers saved in the nodes sequentially. (If the linked list is empty, print a line "E".)

### Input
The first line is an integer n, being the number of operations. Following 
n lines, each line contains one operation described above.

Restrictions

For testcase 1, 1≤n≤10^4

For testcase 2, 1≤n≤10^5
 
For testcase 3, testcase 4 and testcase 5, 1≤n≤10^6
 
In each testcase, 1≤i≤99 for every i in "Insert head", "Insert tail" and "Search" operations
In each testcase, it is guaranteed that the total number of "Search" operations and "Output" operations will not exceed 50

Note that:

In single testcase, the integers i of "Insert head" and "Insert tail" operations may duplicate.
You may receive operations "Remove head", "Remove tail", "Search" or "Output" when the linked list is empty.

### Output
For each "Search" operation and "Output" operation, output one line.

### Sample Input

```
11  
IT 7  
IH 5  
IT 4  
O  
S 4  
RH  
S 7  
O  
RT  
O
S 5
```

### Sample Output
```
5 7 4  
Y  
Y  
7 4  
7  
N
```