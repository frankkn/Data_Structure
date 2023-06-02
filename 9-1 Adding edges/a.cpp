#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

struct DisjointSet{
  int n;
  vector<int> parent, size; // Only the size of each rooted tree's root is corret, but it's enough.

  DisjointSet(int _n):n(_n), parent(n), size(n, 1){
    iota(parent.begin(), parent.end(), 0);
  } 

  int find_root(int x);
  bool Same(int x, int y);
  void Union(int x, int y);
};

int DisjointSet::find_root(int x){
  if(x == parent[x]) return x;
  else return parent[x] = find_root(parent[x]);
}

bool DisjointSet::Same(int x, int y){
  return find_root(x) == find_root(y);
}

void DisjointSet::Union(int x, int y){
  return parent[find_root(x)] = find_root(y);
}

void DisjointSet::Union(int x, int y){
  int rx = find_root(x), ry = find_root(y);
  if(rx == ry) return;
  if(size[rx] > size[ry]) swap(rx,ry);
  parent[rx] = ry;
  size[ry] += size[rx];
}

int main(){
  int n, m;
	cin >> n >> m;
  DisjointSet DS(n);
  int cnt = n, maxcc = 1;
  vector<int> size(n+1, 1);
  for(int i = 0; i < m; ++i){
    int x, y; cin >> x >> y;
    if(!DS.Same(x, y)){
      int new_size = size[x] 
      DS.Union(x, y);
      cnt--;
      maxcc = max(maxcc, DS.size[DS.find_root(x)]);
    }
    cout << cnt << " " << maxcc << "\n";
  }
	return 0;
}
