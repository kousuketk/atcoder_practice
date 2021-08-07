#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
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
  int N, K; cin >> N >> K;
  vector<int> vec_p(N);
  vector<int> vec_c(N);
  rep(i,N) {
    int tmp; cin >> tmp;
    vec_p[i] = --tmp;
  }
  rep(i,N) cin >> vec_c[i];
  ll ans = -INF;
  for(int i = 0; i < N; i++) {
    int next_i = vec_p[i];
    ll loop_size = 0, loop_sum_value = 0, loop_max = vec_c[vec_p[i]]; // 自分も含む(自分の要素は最後)
    vector<ll> vec_loop;  // loop中のvalueを入れていく
    for(int j = 0; j < N; j++) {
      loop_size++;
      loop_sum_value += vec_c[next_i];
      loop_max = max(loop_max, loop_sum_value);
      vec_loop.push_back(vec_c[next_i]);
      if(next_i == i) break; // ループ検出
      next_i = vec_p[next_i];
    }
    // cout << "loop_size:" << loop_size << " loop_sum_value:" << loop_sum_value << " loop_max:" << loop_max << endl;
    if(loop_size >= K) {
      ll tmp_sum = 0;
      rep(i,K) {
        tmp_sum += vec_loop[i];
        ans = max(ans, tmp_sum);
      }
    } else {
      ll loop_count = K/loop_size;
      ll remain = K-loop_count*loop_size;
      ll tmp_loop_sum_value = loop_count*loop_sum_value;
      // cout << "loop_count:" << loop_count << " remain:" << remain << " tmp_loop_sum_value:" << tmp_loop_sum_value << endl;
      ll tmp_sum = 0;
      ll tmp_max = vec_c[vec_p[i]];
      rep(i,remain) {
        tmp_sum += vec_loop[i];
        tmp_max = max(tmp_max, tmp_sum);
      }
      ans = max(ans, loop_max);
      ans = max(ans, tmp_loop_sum_value + tmp_max);
    }
  }
  cout << ans << endl;
}

// 途中で変数の置き換えでミスがあった、境界値とかでデバックしてみるといい