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
const ll mod = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};
// modの割り算(フェルマーの定理)をやってくれる
struct mint {
  ll x;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};

mint modpow(ll a, ll n) {
  mint res = 1;
  while(n > 0) {
    if(n & 1) res = res * a;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

mint choose(ll n, ll a) {
  mint x = 1, y = 1;
  rep(i,a) {
    x *= (n-i);
    y *= i+1;
  }
  return x / y;
}

int main() {
  ll N, a, b; cin >> N >> a >> b;
  mint val = modpow(2, N) - 1;
  val -= choose(N, a);  // nCa
  val -= choose(N, b);  // nCb
  cout << val.x << endl;
  return 0;
}

// https://atcoder.jp/contests/abc156/tasks/abc156_d