#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(){
  int n,m; cin >> n >> m;
  vector<vector<int>> G;
  G.assign(n+1, {});
  vector<int> in_deg(n+1, 0);
  deque<int> Q;
  for(int i = 0; i < m; ++i){
    int x,y; cin >> x >> y;
    G[x].emplace_back(y);
    in_deg[y]++;
  }
  for(int i = 1; i <= n; ++i){
  	if(in_deg[i] == 0){
      Q.emplace_back(i);
    }
  }
  int cnt = 0;
  while(!Q.empty()){
    int v = Q.front(); Q.pop_front(); cnt++;
    for(auto u: G[v]){
      if(--in_deg[u] == 0){
        Q.emplace_back(u);
      }
    }
  }
  if(cnt == n)	cout << "YES\n";
  else cout << "NO\n";
  return 0;
}