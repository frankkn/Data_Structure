#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n, m, q; cin >> n >> m >> q;
  vector<vector<int>> G(n+1, vector<int>(n+1, 0));
  for(int i = 0; i < m; ++i){
  	int x, y; cin >> x >> y;
    G[x][y] = 1;
    G[y][x] = 1;
  }
  while(q--){
    char op;
  	cin >> op;
  	if(op == 'D'){
      int v; cin >> v;
      int d = 0;
      for(int i = 1; i <= n; ++i){
      	if(G[v][i] == 1)	d++;
      }
      cout << d << "\n";
    }else{
      int a, b; cin >> a >> b;
      if(G[a][b] == 1){
      	cout << "Y\n";
      }else{
      	cout << "N\n";
      }
    }
  }
  return 0;
}