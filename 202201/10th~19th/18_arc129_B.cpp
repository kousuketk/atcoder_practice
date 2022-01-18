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
  vector<P> vec(N);
  rep(i,N) cin >> vec[i].first >> vec[i].second;
  bool flag = true;
  int max_l, min_r, co_l, co_r;
  rep(i,N) {
    if(i == 0) {
      max_l = vec[0].first;
      co_l = vec[0].first;
      min_r = vec[0].second;
      co_r = vec[0].second;
      cout << 0 << endl;
      continue;
    }
    int l = vec[i].first;
    int r = vec[i].second;
    max_l = max(max_l, l);
    min_r = min(min_r, r);
    // 判定
    if(flag) {
      if(co_l <= l && r <= co_r) co_l = l, co_r = r;
      else if(l <= co_l && co_l <= r && r <= co_r) co_r = r;
      else if(co_l <= l && l <= co_r && co_r <= r) co_l = l;
      else if(l <= co_l && co_r <= r);
      else flag = false;
    }
    // 出力
    if(flag) {
      cout << 0 << endl;
    } else {
      int tmp = (max_l - min_r)/2;
      int ans = max_l - (min_r + tmp);
      cout << ans << endl;
    }
  }
}