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

// 最長増加部分列の数から差を取る
int main() {
  int N; cin >> N;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  vector<int> lis(N, INF);
  rep(i,N) {
    // lisに対してlower_boundをとっていく
    auto itr = lower_bound(ALL(lis), vec[i]);
    *itr = vec[i];
  }
  int val = lower_bound(ALL(lis), INF) - lis.begin();
  int ans = N - val;
  cout << ans << endl;
  return 0;
}