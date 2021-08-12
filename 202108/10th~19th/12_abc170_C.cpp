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
  int x, N; cin >> x >> N;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  vector<int> vec_all(102);
  rep(i,102) vec_all[i] = i;
  vector<int> vec_diff; // 差集合
  sort(ALL(vec));
  set_difference(ALL(vec_all), ALL(vec), back_inserter(vec_diff));
  auto itr_r = lower_bound(ALL(vec_diff), x);
  auto itr_l = itr_r - 1;
  int diff_l = abs(*itr_l - x);
  int diff_r = abs(*itr_r - x);
  int ans;
  if(diff_l <= diff_r) ans = *itr_l;
  else ans = *itr_r;
  cout << ans << endl;
}