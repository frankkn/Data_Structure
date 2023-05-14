#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<string.h>
#include<cmath>
#define MAXD (1e+9)
using namespace std;


struct Node
{
  string node_type;
  string name;
  int id;
  Node(string node_type, string name, int id):node_type(node_type), name(name), id(id) {}
};

bool illegal(string name1, string name2)
{
  if(name1 == "SOURCE"){
    if(name2 == "SPY") return true;
    else return false;
  }else if(name1 == "SPY"){
    if(name2 == "SOURCE" || name2 == "SPY") return true;
    else return false; 
  }else if(name1 == "CIV"){
    if(name2 == "HQ") return true;
    else return false;
  }else{
    if(name2 == "CIV") return true;
    else return false;
  }
}

void dijkstra(const vector<vector<pair<int,double>>> &G, int start, int cnt, vector<double>& d,  vector<int>& predecessor)
{
  // vector<double> d(cnt, MAXD); // node num: 1~ (cnt-1)
  vector<bool> visited(cnt, false);
  using QueuePair = pair<int, int>;
  priority_queue<QueuePair, vector<QueuePair>, greater<QueuePair>> Q;
  d[start] = 0;
  Q.emplace(d[start], start);
  while(Q.size()){
    int u = Q.top().second;
    Q.pop();
    if(visited[u]) continue;
    visited[u] = true;
    for(auto [v, cost] : G[u]){
      if(d[v] > d[u] + cost){
        predecessor[v] = u;
        d[v] = d[u] + cost;
        Q.emplace(d[v], v);
      }
    }
  }
}

int main(){
  vector<vector<pair<int, double>>> G;
  vector<vector<int>> message;
  message.assign(100, vector<int>(100,0));
  G.assign(100, {});
  vector<Node*> node_list;
  node_list.emplace_back(new Node("dummy", "dummy", 0));
  int cnt = 1;
  int start = -1, end = -1;
  while(true){
    string s; cin >> s;
    if(s == "INSERT"){
      string node_type, name;
      cin >> node_type >> name;
      if(node_type == "SOURCE") start = cnt;
      if(node_type == "HQ") end = cnt;
      node_list.emplace_back(new Node(node_type, name, cnt));
      cnt++;
    }else if(s == "INSERT_EDGE"){
      int id1, id2; cin >> id1 >> id2;
      double m; cin >> m;
      message[id1][id2] = m;
      message[id2][id1] = m;
      string node_tpye1 = node_list[id1]->node_type, node_tpye2 = node_list[id2]->node_type;
      if(!illegal(node_tpye1, node_tpye2)){
        double d = (round((1000.0/m)*100))/100;
        G[id1].emplace_back(make_pair(id2, d));
        G[id2].emplace_back(make_pair(id1, d));
      }else{
        G[id1].emplace_back(make_pair(id2, MAXD));
        G[id2].emplace_back(make_pair(id1, MAXD));
      }
    }else{
      vector<double> d(cnt, MAXD);
      vector<int> predecessor(cnt, -1);
      dijkstra(G, start, cnt, d, predecessor);
      
      
      // Output shortest path from start to end
      int tmp = end;
      int total_msg = 0;
      stack<int> ids;
      while(tmp != -1){
        ids.push(tmp);
        if(predecessor[tmp] != -1)  total_msg += message[tmp][predecessor[tmp]];
        tmp = predecessor[tmp];
      }
      while(!ids.empty()){
        int i = ids.top(); ids.pop();
        cout << node_list[i]->name;
        if(ids.size() != 0){
          cout << " -> ";
        }
      }
      cout << endl;
      
      // Output total messages in shortest path
      cout << total_msg << endl;

      // Output minimum distance between 
      cout << d[end] << endl;
      break;
    }
  }
  

  //check Graph infomation
  /*
  for(int i = 1; i < cnt; ++i){
    for(auto [x, y]: G[i]){
      cout << "(" << x << "," << y << ")";
    }
    cout << endl;
  }*/

  return 0;
}