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
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int main() {
  int N, K; cin >> N >> K;
  vector<int> vec(N);  // ただ全部の整数を入れておくだけ
  vector<P> vec_abs(N);  // 絶対値の大きい順で, 番号も格納
  vector<int> vec_plus; // プラスの大きい順に並び替えとく
  vector<int> vec_minus; // プラスの大きい順に並び替えとく
  rep(i,N) {
    int tmp; cin >> tmp;
    vec[i] = tmp;
    vec_abs[i].first = abs(tmp); vec_abs[i].second = i;
    if(tmp >= 0) vec_plus.push_back(tmp);
    else vec_minus.push_back(tmp);
  }
  sort(ALL(vec_abs), greater());
  sort(ALL(vec_plus), greater());
  sort(ALL(vec_minus));
  // K個選ぶ
  int ans = 1;
  int idx_plus = 0;
  int idx_minus = 0;
  int size_plus = vec_plus.size();
  int size_minus = vec_minus.size();
  int over = 0;
  // 全部プラスの時orN==Kで全部選ぶ時
  if(size_minus == 0 || N == K) {
    rep(i,K) ans = (ans*vec[vec_abs[i].second]) % MOD;
    if(ans < 0) ans += MOD;
    cout << ans << endl;
    return 0;
  }
  // 全部マイナスの時
  if(size_plus == 0) {
    rep(i,K) ans = (ans*vec[vec_abs[N-i-1].second]) % MOD;
    if(ans < 0) ans += MOD;
    cout << ans << endl;
    return 0;
  }
  rep(i,K) {
    // K-1のときに符号を調節
    if(i == K-1) {
      // プラスの時はプラス, マイナスのときはマイナス
      if(ans >= 0) ans = (ans*vec_plus[idx_plus]) % MOD;
      else ans = (ans*vec_minus[idx_minus]) % MOD;
    } else {
      if(idx_plus == size_plus-1 || idx_minus == size_minus-1) over++;
      int idx = vec_abs[i+over].second;
      int value = vec[idx];
      if(value >= 0) {
        if(idx_plus == size_plus-1) {
          over++;
          idx = vec_abs[i+over].second;
          value = vec[idx];
        } else {
          idx_plus++;
        }
      } else {
        if(idx_minus == size_minus-1) {
          over++;
          idx = vec_abs[i+over].second;
          value = vec[idx];
        } else {
          idx_minus++;
        }
      }
      ans = (ans*value) % MOD;
    }
  }
  if(ans < 0) ans += MOD;
  cout << ans << endl;
}