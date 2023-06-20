#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

typedef struct {
	int u,v;
	ll cost;
} edge;
bool cmp(edge a, edge b) {
	return a.cost < b.cost;
}
vector<int> fa;
vector<edge> Edges;
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y) {
	fa[find(y)] = find(x); 
}
signed main() {
	int n,m;cin>>n>>m;
	fa.resize(n+1);
	Edges.resize(m);
	for(int i=0;i<=n;i++) fa[i] = i;
	for(int i=0;i<m;i++) cin>>Edges[i].u>>Edges[i].v>>Edges[i].cost;
	sort(Edges.begin(),Edges.end(),cmp);
  	ll ans = 0;
  	for(int i=0;i<m;i++) {
    	if(find(Edges[i].u) != find(Edges[i].v)) {
        	unite(Edges[i].u,Edges[i].v);
          	ans += Edges[i].cost;
        }
    }
  	cout<<ans;
}