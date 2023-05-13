#include <iostream>
#include <vector>
using namespace std;

void preorder(int node, vector<int>& pre, vector<vector<int>>& Tree){
  if(node == -1) return;
  pre.emplace_back(node);
  preorder(Tree[node][0], pre, Tree);
  preorder(Tree[node][1], pre, Tree);
}

int main(){
  int n; cin >> n;
  vector<vector<int>> Tree;
  Tree.assign(n+1, vector<int>(2,0));
  vector<int> used(n+1, 0);
  for(int i = 1; i <= n; ++i){
  	int L, R; cin >> L >> R;
    Tree[i][0] = L;
    Tree[i][1] = R;
    if(L != -1) used[L] = 1;
    if(R != -1) used[R] = 1;
  }
  int root = -1;
  for(int i = 1; i <= n; ++i){
  	if(used[i] == 0){
      root = i;
      break;
    }
  }
  vector<int> pre;
  preorder(root, pre, Tree);
  cout << pre.back();
  
  return 0;
}