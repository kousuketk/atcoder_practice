#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;

int main() {
  ll n;
  cin >> n;
  ll x = 1000;
  ll ans = 0;
  while(n >= x) {
    ans += n-x+1;
    x *= 1000;
  }
  cout << ans << endl;
  return 0;
}