#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    // 最下位ビットが1のときに計算(掛けていく, 最終的に指数の計算に持っていく)
    if (n & 1) res = res * a % mod;
    // a, a^2, a^4, a^8, a^16, a^32, ...
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  ll N, a, b; cin >> N >> a >> b;
  ll val = modpow(2, N, MOD) - 1;
  ll ax = 1, ay = 1;
  rep(i,a) ax = ax*(N-i) % MOD;
  rep(i,a) ay = ay*(a-i) % MOD;
  ll ayy = modpow(ay, MOD-2, MOD);
  ll a_val = ax*ayy % MOD;
  ll bx = 1, by = 1;
  rep(i,b) bx = bx*(N-i) % MOD;
  rep(i,b) by = by*(b-i) % MOD;
  ll byy = modpow(by, MOD-2, MOD);
  ll b_val = bx*byy % MOD;
  ll ans = val - a_val - b_val;
  while(ans < 0) ans += MOD;
  cout << ans << endl;
  return 0;
}