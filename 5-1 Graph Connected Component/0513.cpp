#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> G;
vector<int> used;

void dfs(int i){
  if(used[i] == 0){
  	used[i] = 1;
    for(auto u: G[i]){
    	dfs(u);
    }
  }
}

int main(){
  int t; cin >> t;
  while(t--){
    int n, m; cin >> n >> m;
	  G.assign(n+1, {});
    used.assign(n+1, 0);
    
    for(int i = 0; i < m; ++i){
      int x, y; cin >> x >> y;
      G[x].emplace_back(y);
      G[y].emplace_back(x);
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
    	if(used[i] == 0){
        dfs(i);
        cnt++;
      }
    }
  	cout << cnt << "\n";
  }

  return 0;
}