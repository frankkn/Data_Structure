#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int BS(vector<ll> &a, int L, int R, ll x){
	while(L < R){
        int M = L + (R - L) / 2;
        if(a[M] <= x) R = M;
        else L = M + 1;
    }
	return R;
}

int main(){
	int n, m; cin >> n >> m;
  	vector<ll> a(n, 0);
  	for(int i = 0; i < n; ++i) cin >> a[i];
  	for(int i = 0; i < m; ++i){
    	ll x; cin >> x;
      	int idx = BS(a, 0, n, x);
      	if(a[idx] != x){
        	cout << "N";
        }else{
        	cout << "Y";
        }
    	i == m ? cout << "\n": cout << " "; 
    }
  	return 0;
}