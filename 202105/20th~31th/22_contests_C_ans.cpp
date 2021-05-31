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
  ll N;
  cin >> N;
  vector<ll> A(N), B(N), C(N);
  rep(i,N) cin >> A.at(i);
  rep(i,N) cin >> B.at(i);
  rep(i,N) cin >> C.at(i);
  vector<ll> cnt(N+1);
  ll ans = 0;
  rep(i,N) cnt[A[i]]++;
  rep(j,N) ans += cnt[B[C[j]-1]];
  cout << ans << endl;
  return 0;
}