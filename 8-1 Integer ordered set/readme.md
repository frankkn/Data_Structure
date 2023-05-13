## [Integer ordered set](http://adalab.cs.nthu.edu.tw/contest/48/problem/8-1)
### Description

* I x : Insert. If x is NOT in the set, insert x into the set. Otherwise, don't do anything. Print the size of the set after finishing the operation.
* D x : Delete. If x is in the set, delete x from the integer set. Otherwise, don't do anything. Print the size of the set after finishing the operation.
* S x : Search. If x is in the set, print "YES". Otherwise, print "NO".
* L x : Lower bound. Print the smallest element greater than or equal to x in the set. If the element doesn't exist, print "−1".
* U x : Upper bound. Print the smallest element greater than x in the set. If the element doesn't exist, print "−1".

There are at least two ways to get AC.

One is to write a binary search tree by yourself. The template below gives the functions of the BST for reference.

Another way is to use set<int> and maintain the set by functions in the standard library.

Note
* The numbers x in this problem are generated randomly.

### Input

The first line is an integer n which is the number of operations.

Following n lines, each line contains one of the operations described above.

Restrictions

* 1 ≤ n ≤ 10^5
* 1 ≤ x ≤ 10^9 for every x in all operations

Testcases 1 and 2:
* only Insert and Search operations.

Testcases 3 and 4:
* no Delete operations.

Testcases 5 ~ 10:
* no further constraints.

### Output

For each operation:

* I x or D x : Print the size of the set after finishing the operation.
* S x : If x is in the set, print "YES". Otherwise, print "NO".
* L x or U x : Print the element if the required element is in the set. Otherwise, print "-1".

### Sample Input 1

```
19
I 4
I 8
I 7
I 6
I 3
D 7
D 5
D 4
S 8
I 8
S 7
L 9
L 8
L 7
L 6
U 9
U 8
U 7
U 6
```

### Sample Output 1

```
1
2
3
4
5
4
4
3
YES
3
NO
-1
8
8
6
-1
-1
8
8
```

### Hint

Template:

```
#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;
    Node(int _key, Node* _left = nullptr, Node* _right = nullptr, Node* _parent = nullptr) 
        : key(_key), left(_left), right(_right), parent(_parent) {}
} Node;

// Input:   The root node of the tree.
// Return:  The node with minimum value of the tree.
Node* findmin(Node* root) {
    while(root -> left)
        root = root -> left;
    return root;
}

// Input:   The root node of the tree.
// Return:  The node with maximum value of the tree.
Node* findmax(Node* root) {
    while(root -> right)
        root = root -> right;
    return root;
}

// Input:   The root node of the tree and the value we want to find.
// Return:  The node with the value. If the node doesn't exist, return nullptr.
Node* search(Node* root, int k) {
    if (root == nullptr)    return nullptr;
    if (root -> key == k)    return root;
    if (root -> key > k)
        return search(root -> left, k);
    else
        return search(root -> right, k);
}

// Input:   The root node of the tree we want to insert the node into.
void insertnode(Node* &root, Node* node) {
    if (root == nullptr) {
        root = node;
        return;
    }
    if (root -> key > node -> key) {
        if (root -> left) {
            insertnode(root -> left, node);
        } else {
            root -> left = node;
            node -> parent = root;
        }
    } else if (root -> key < node -> key) {
        if (root -> right) {
            insertnode(root -> right, node);
        } else {
            root -> right = node;
            node -> parent = root;
        }
    }
    return;
}

// Transplant(root, x, y) links x's parent to y and y's parent is changed accordingly under the tree root
void transplant(Node* &root, Node* x, Node* y) {
    if (x -> parent == nullptr) {
        root = y;
    } else if (x -> parent -> left == x) {
        x -> parent -> left = y;
    } else {
        x -> parent -> right = y;
    }

    if (y) {
        y -> parent = x -> parent;
    }
    return;
}

// Input:   The root node of the tree and the node we want to delete
void deletenode(Node* &root, Node *x) {
    /* Case 1: x is a leaf */
    if (x -> left == nullptr && x -> right == nullptr)
        transplant(root, x, nullptr);
    /* Case 2: x has one child */
    else if (x -> left == nullptr)
        transplant(root, x, x -> right);
    else if (x -> right == nullptr)
        transplant(root, x, x -> left);
    /* Case 3: x has two children */
    else {
        Node* y = findmin(x -> right);
        if (y -> parent == x) {
            transplant(root, x, y);
            y -> left = x -> left;
            x -> left -> parent = y;
        } else {
            transplant(root, y, y -> right);
            transplant(root, x, y);
            y -> right = x -> right;
            y -> left = x -> left;
            x -> right -> parent = x -> left -> parent = y;
        }
    }
    free(x);
}

// Input:   The root node of the tree and the value of x
// Return:  The smallest element greater than or equal to x in the set.
//          If the value doesn't exist, return -1
int findlowerbound(Node *root, int x) {
    int ans = -1;
    if (x < root -> key) {
        if (root -> left != NULL)
            ans = findlowerbound(root -> left, x);

        if (ans != -1) 
            ans = min(root -> key, ans);
        else 
            ans = root -> key;
    } else if (x > root -> key) {
        if (root -> right != NULL)
            ans = findlowerbound(root -> right, x);
    } else /*(node -> key == x)*/
        ans = x;
    return ans;
}

// Input:   The root node of the tree and the value of x
// Return:  The smallest element greater than x in the set.
//          If the value doesn't exist, return -1
int findupperbound(Node *root, int x) {
    int ans = -1;
    if (x < root -> key) {
        if (root -> left != NULL)
            ans = findupperbound(root -> left, x);

        if (ans != -1)
            ans = min(root -> key, ans);
        else 
            ans = root -> key;
    } else /*if (x >= root -> key)*/ {
        if (root -> right != NULL)
            ans = findupperbound(root -> right, x);
    }
    return ans;
}

int main() {
    // TODO
    return 0;
}
```