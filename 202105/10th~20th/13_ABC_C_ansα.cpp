#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;
 
int main() {
  ll n;cin >> n;
  ll ans=0, out=1e6;
  while(out-ans>1) {
    ll mid = (ans+out)/2;
    if (stoll(to_string(mid)+to_string(mid))<=n) ans = mid;
    else out = mid;
  }
  cout << ans << endl;
  return 0;
}