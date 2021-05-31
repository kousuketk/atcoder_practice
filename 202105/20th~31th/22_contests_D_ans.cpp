#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;

ll c[61][61];

int main() {
  int a, b;
  ll k;
  cin >> a >> b >> k;

  c[0][0] = 1;
  rep(i,60) {
    rep(j,i+1) {
      c[i+1][j] += c[i][j];
      c[i+1][j+1] += c[i][j];
    }
  }

  string ans;
  while(a+b > 0) {
    ll x = 0;
    if(a >= 1) x = c[a+b-1][a-1];
    if(k <= x) {
      ans += 'a';
      --a;
    } else {
      ans += 'b';
      --b;
      k -= x;
    }
  }
  cout << ans << endl;
}