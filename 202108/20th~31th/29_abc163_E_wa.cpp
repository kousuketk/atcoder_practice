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
  int N; cin >> N;
  vector<P> vec_sorted(N);
  rep(i,N) {
    int tmp; cin >> tmp;
    vec_sorted[i] = P(tmp, i);
  }
  sort(ALL(vec_sorted), greater());
  ll ans = 0;
  int itr = 0;
  int itr_back = N-1;
  rep(i,N) {
    int val = vec_sorted[i].first;
    int idx = vec_sorted[i].second;
    if(abs(idx-itr) >= abs(idx-itr_back)) {
      ans += val * abs(idx-itr);
      itr++;
    } else {
      ans += val * abs(idx-itr_back);
      itr_back--;
    }
  }
  cout << ans << endl;
}

// 貪欲法で考えたけどダメ
// →右or左の方向を決めたら、貪欲法で行ける
// dp[i][l][r]：大きい方からi個まで左右を決めて左をl回, 右をr回使った時の最大値
// →dp[i][l]：r = i-lで要素を減らせる
// ↓以下のようにdpを計算する
// rep(i,N) {
//   int pi = vec_sorted[i].second;
//   rep(l,i+1) {
//     int r = i-l;
//     chmax(dp[i+1][l+1], dp[i][l]+ll(pi-l)*a[pi]);
//     chmax(dp[i+1][l], dp[i][l]+ll((n-r-1)-pi)*a[pi]);
//   }
// }