#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<ll,ll>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
// const int INF = 1001001001;
const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int N; cin >> N;
  ll max_x = -INF;
  ll min_x = INF;
  ll max_y = -INF;
  ll min_y = INF;
  rep(i,N) {
    ll x, y; cin >> x >> y;
    max_x = max(max_x, x+y);
    min_x = min(min_x, x+y);
    max_y = max(max_y, x-y);
    min_y = min(min_y, x-y);
  }
  ll ans = max(max_x - min_x, max_y - min_y);
  cout << ans << endl;
}

// abc178:https://atcoder.jp/contests/abc178/tasks/abc178_e
// 参考にした:https://illumination-k.dev/posts/atcoder/manhattan