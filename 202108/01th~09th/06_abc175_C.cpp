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
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  ll x, k, d; cin >> x >> k >> d;
  ll ans;
  // 初期位置から0に行けない時(abs(x) >= k*d)
  // if(abs(x) > k && abs(x) >= k*d) {
  //   ans = abs(x) - k*d;
  //   cout << ans << endl;
  //   return 0;
  // }
  // 座標0を超える時→残りの移動回数の偶奇で場合分け
  ll count = abs(x)/d;
  if(count*d != abs(x)) count++;
  ll k2 = k - count; // 残りの回数
  if(k2 < 0) {
    ans = abs(x) - k*d;
    cout << ans << endl;
    return 0;
  }
  ll over_x = abs(x) - count*d;
  // over_x(偶数), abs(over_x) - d(奇数)
  if(k2 % 2 == 0) ans = over_x;
  else ans = abs(over_x) - d;
  cout << abs(ans) << endl;
  return 0;
}

// コメントアウトの部分のk*dのところでオーバーフローしててwaしていた