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
  int N, X, Y; cin >> N >> X >> Y;
  vector<P> vec(N);
  int cnt_a = 0;
  int cnt_b = 0;
  rep(i,N) {
    int a, b; cin >> a >> b;
    vec[i] = P(a,b);
    cnt_a += a;
    cnt_b += b;
  }
  if(cnt_a < X || cnt_b < Y) {
    cout << "-1" << endl;
    return 0;
  }
  int left_x = X;
  int left_y = Y;
  sort(ALL(vec));
  int ans = 0;
  while(left_x > 0) {
    // left_xより大きい要素があったら、その中で一番大きいyをえらぶ。
    auto itr = lower_bound(ALL(vec), P(left_x,-1));
    if(itr != vec.end()) {
      auto max_itr = itr;
      P tmp_par = *itr;
      int max_b = tmp_par.second;
      while(itr != vec.end()) {
        P tmp_in = *itr;
        if(max_b < tmp_in.second) {
          max_b = tmp_in.second;
          max_itr = itr;
        }
        itr++;
      }
      P tmp = *max_itr;
      left_x -= tmp.first;
      left_y -= tmp.second;
      vec.erase(max_itr, max_itr+1);
      ans++;
    } else { // なかったら上から取っていく
      P tmp = vec.back();
      int a = tmp.first;
      int b = tmp.second;
      left_x -= a;
      left_y -= b;
      vec.pop_back();
      ans++;
    }
  }
  // vecをvec_yで並び替える
  int left_all = N-ans;
  vector<int> vec_y(left_all);
  rep(i,left_all) {
    vec_y[i] = vec[i].second;
  }
  sort(ALL(vec_y), greater());
  int cnt_i = 0;
  while(left_y > 0) {
    int b = vec_y[cnt_i];
    left_y -= b;
    ans++;
    cnt_i++;
  }
  cout << ans << endl;
  return 0;
}