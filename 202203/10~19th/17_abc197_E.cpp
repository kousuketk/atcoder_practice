#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<ll,ll>;
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

ll dp[200010][2];
int main() {
  ll N; cin >> N;
  map<ll, P> mp;  // ボールの色の整数に対して、最小, 最大の座標を持つ
  mp[0] = P(0, 0);
  rep(i,N) {
    ll x, c; cin >> x >> c;
    if(!mp.count(c)) {
      mp[c] = P(x, x);
    } else {
      mp[c].first = min(mp[c].first, x);
      mp[c].second = max(mp[c].second, x);
    }
  }
  int skip = 0;
  for(int i = 1; i <= N; i++) {  // 全ての色に対してdpしていく
    if(mp.count(i)) {
      ll before_min_idx = mp[i-skip-1].first;
      ll before_max_idx = mp[i-skip-1].second;
      ll now_min_idx = mp[i].first;
      ll now_max_idx = mp[i].second;
      dp[i][0] = min(dp[i-1][0] + abs(before_min_idx - now_max_idx) + abs(now_max_idx - now_min_idx), 
                     dp[i-1][1] + abs(before_max_idx - now_max_idx) + abs(now_max_idx - now_min_idx));
      dp[i][1] = min(dp[i-1][0] + abs(before_min_idx - now_min_idx) + abs(now_min_idx - now_max_idx),
                     dp[i-1][1] + abs(before_max_idx - now_min_idx) + abs(now_min_idx - now_max_idx));
      skip = 0;
    } else {
      dp[i][0] = dp[i-1][0];
      dp[i][1] = dp[i-1][1];
      skip++;
    }
  }
  // N-skipに最後に動いた位置
  ll min_idx = mp[N-skip].first;
  ll max_idx = mp[N-skip].second;
  ll ans = min(dp[N][0] + abs(min_idx), dp[N][1] + abs(max_idx));
  cout << ans << endl;
  return 0;
}