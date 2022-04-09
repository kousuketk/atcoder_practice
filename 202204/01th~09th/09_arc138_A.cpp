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

// 後半をソートして、見ていく
int main() {
  int N, K; cin >> N >> K;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  vector<P> ato(N-K);
  for(int i = K; i < N; i++) {
    ato[i-K] = P(vec[i], i);  // val, idx
  }
  sort(ALL(ato));
  vector<bool> seen(N, false);
  int ans = INF;
  for(int i = K-1; i >= 0; i--) {
    int a = vec[i];
    auto itr = lower_bound(ALL(ato), P(a, INF));
    while(itr != ato.end()) {
      P tmp = *itr;
      // int val = tmp.first;
      int idx = tmp.second;
      if(seen[idx]) break;;
      seen[idx] = true;
      int tmp_ans = idx - i;
      ans = min(ans, tmp_ans);
      itr++;
    }
  }
  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}