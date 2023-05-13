#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
  priority_queue<int, vector<int>, greater<int>> Q;
  int q; cin >> q;
  while(q--){
  	char op; cin >> op;
    if(op == '1'){
      int v; cin >> v;
      Q.push(v);
    }else if(op == '2'){
      if(!Q.empty())	Q.pop();
    }else{
      if(!Q.empty())	cout << Q.top() << "\n";
      else cout << "EMPTY\n";
    }
  }
  return 0;
}