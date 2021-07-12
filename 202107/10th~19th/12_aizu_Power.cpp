#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
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
  int n, m; cin >> n >> m;
  cout << modpow(n, m, 1000000007) << endl;
}