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

// スコア順でidxをマイナス表記していれば、前から見た時常にそのidxの差を取れる
int main() {
  int N, K; cin >> N >> K;
  vector<P> vec(N);
  rep(i,N) {
    int a; cin >> a;
    vec[i] = P(a, -i);
  }
  sort(ALL(vec));
  int mx_idx = -1;
  int ans = INF;
  rep(i,N) {
    int a = vec[i].first;
    int idx = -vec[i].second;
    if(idx < K) {
      mx_idx = max(mx_idx, idx);
    } else {
      if(mx_idx == -1) continue;;
      ans = min(ans, idx-mx_idx);
    }
  }
  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}