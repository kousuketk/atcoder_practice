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
  int N, D; cin >> N >> D;
  vector<P> left(N);
  vector<P> right(N);
  vector<bool> seen(N);  // i番目はすでに壊されているか?
  rep(i,N) {
    int l, r; cin >> l >> r;
    left[i] = P(l, i);
    right[i] = P(r, i);
  }
  sort(ALL(left));
  sort(ALL(right));
  int ans = 0;
  for(int idx = 0; idx < N; idx++) {
    int i = right[idx].second;
    if(seen[i]) continue;
    int r = right[idx].first;
    int tmp = r + D - 1;
    auto itr = lower_bound(ALL(left), P(tmp, N)) - 1;
    int idx_left = itr - left.begin();
    while(idx_left >= 0 && !seen[idx_left]) {  // 破壊済みでなかったら、前に探索してく(まとめて破壊できる)
      int left_i = left[idx_left].second;
      seen[left_i] = true;
      idx_left--;
    }
    ans++;
  }
  cout << ans << endl;
}