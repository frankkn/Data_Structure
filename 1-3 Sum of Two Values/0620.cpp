#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, int> m;

int main(){
	int n, target; cin >> n >> target;
    vector<int> a(n+1, 0);
    for(int i = 1; i <= n; ++i) cin >> a[i];
  	for(int i = 1; i <= n; ++i){
    	if(m.count(target - a[i])){
        	cout << m[target- a[i]] << " " << i << "\n";
          return 0;
        }else{
        	m[a[i]] = i;
        }
    }
  cout << "IMPOSSIBLE\n";


	return 0;
}