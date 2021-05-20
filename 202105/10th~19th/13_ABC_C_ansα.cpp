#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;
 
int main() {
  ll n;cin >> n;
  ll left=0, right=1000000;
  while(left+1<right) {
    ll mid = (left+right)/2;
    if (stoll(to_string(mid)+to_string(mid))<=n) left = mid;
    else right = mid;
  }
  cout << left << endl;
  return 0;
}