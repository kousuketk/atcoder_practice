#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 998244353;
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
  ll N, K, M; cin >> N >> K >> M;
  N = N % MOD;
  K = K % MOD;
  M = M % MOD;
  ll tmp_cnt = modpow(K, N, MOD-1);
  ll ans = modpow(M, tmp_cnt, MOD);
  cout << ans << endl;
}