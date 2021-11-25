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
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

ll dp[3010]; // i回目の結果
int N;
vector<ll> vec;
ll rec(int i, int idx_a, int idx_b) {
  // if(idx_a > idx_b) return 0;
  if(dp[i] != INF) return dp[i];
  if(i % 2 == 0) { // 太郎君の版
    // 先頭要素, 末尾を取り除く
    return dp[i] = max(rec(i+1, idx_a + 1, idx_b) + vec[idx_a],
                       rec(i+1, idx_a, idx_b - 1) + vec[idx_b]);
  } else {
    return dp[i] = min(rec(i+1, idx_a + 1, idx_b) - vec[idx_a],
                       rec(i+1, idx_a, idx_b - 1) - vec[idx_b]);
  }
}

int main() {
  cin >> N;
  vec.resize(N);
  rep(i,N) cin >> vec[i];
  rep(i,3010) dp[i] = INF;
  dp[N-1] = 0;
  ll ans = rec(0, 0, N-1);
  cout << ans << endl;
}