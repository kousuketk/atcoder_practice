#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
int const_mod = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

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
  ll N, Q; cin >> N >> Q;
  vector<ll> A(N);
  vector<ll> C(Q);
  rep(i,N) cin >> A[i];
  rep(i,Q) {
    ll tmp; cin >> tmp;
    tmp--;
    C[i] = tmp;
  }
  // Aの累積和を取る、街x~街yへの移動をO(1)で取りたい
  // 街l~街rへの移動:S[r] - S[l]
  vector<ll> S(N);
  for(ll i = 1; i < N; i++) {
    // modpow(A[i-1], A[i], const_mod):i-1とiのコスト
    S[i] = (S[i-1] + modpow(A[i-1], A[i], const_mod)) % const_mod;
  }
  ll ans = 0;
  for(ll i = 0; i < Q; i++) {
    if(i == 0) {
      // 街0~街rまでのコスト
      ll r = C[i];
      ans = (ans + S[r]) % const_mod;
    } else {
      // 街l~街rまでのコスト, C[i-1]とC[i]
      ans = (ans + abs(S[C[i-1]]-S[C[i]]) % const_mod) % const_mod;
    }
  }
  ans = (ans + S[C[Q-1]] % const_mod) % const_mod;
  cout << ans % const_mod << endl;
  return 0;
}