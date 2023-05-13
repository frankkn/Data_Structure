#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using It = vector<int64_t>::iterator;

void merge_sort(It left, It right){
	int64_t d = distance(left, right);
  if(d > 1){
    It mid = next(left, d/2);
    merge_sort(left, mid);
    merge_sort(mid, right);
    inplace_merge(left, mid, right);
  }
}

int main(){
  int64_t n;
  cin >> n;
  vector<int64_t> a(n,0);
  for(int64_t i = 0; i < n; ++i) cin >> a[i];
  merge_sort(a.begin(), a.end());
  for(int64_t i = n-1; i >= 0; --i){
    cout << a[i];
    if(i != 0) cout << " ";
  }
  return 0;
}