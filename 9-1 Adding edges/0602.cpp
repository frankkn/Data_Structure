#include <iostream>
#include <vector>
using namespace std;

class DisjointSet 
{
  public:
    vector<int> parent;
    int find_root(int x) 
    {
      if (x == parent[x]) return x;
      int root = find_root(parent[x]);
      return parent[x] = root; // 路徑壓縮
    }


    DisjointSet(int n):parent(n + 1) { init(); }
    void init() 
    {
      for (int i = 0; i < parent.size(); ++i)
        parent[i] = i;
    }
    bool Same(int a, int b) { return find_root(a) == find_root(b); }
    void Union(int a, int b) { parent[find_root(a)] = find_root(b); }
};

int main(){
  int n, m;
	cin >> n >> m;
  DisjointSet DS(n);
  int cnt = n, maxcc = 1;
  vector<int> component_size(n+1, 1);
  for(int i = 0; i < m; ++i){
    int x, y; cin >> x >> y;
    if(!DS.Same(x, y)){
      int new_size = component_size[DS.find_root(x)] + component_size[DS.find_root(y)];
      component_size[DS.find_root(x)] = new_size;
      component_size[DS.find_root(y)] = new_size;
      DS.Union(x, y);
      cnt--;
      maxcc = max(maxcc, new_size);
    }
    cout << cnt << " " << maxcc << "\n";
  }
	return 0;
}