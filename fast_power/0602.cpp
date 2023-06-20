#include <iostream>
#define ll long long
#define MOD ((ll)1e9+7)
using namespace std;

ll fast_power(ll a, ll b){
  if(b == 0) return 1ll;
  ll res = 1 % MOD;
  ll tmp = fast_power(a, b/2);
  if(b % 2 == 1) return ((tmp*tmp)%MOD *a) %MOD;
  else return tmp * tmp % MOD;
}

int main(){
  int t; cin >> t;
  while(t--){
    ll a, b; cin >> a >> b;
    if(a == 0 && b == 0) {cout << "1\n"; continue;}
    ll ans = fast_power(a, b);
    cout << ans << endl;
  }

  return 0;
}