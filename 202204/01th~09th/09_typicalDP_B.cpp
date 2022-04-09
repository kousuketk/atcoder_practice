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
  int N, K; cin >> N >> K;
  vector<int> h(N);
  rep(i,N) cin >> h[i];
  vector<int> dp(N, INF);
  dp[0] = 0;
  for(int i = 0; i < N; i++) {
    for(int k = 1; k <= K; k++) {
      if(i+k >= N) break;
      dp[i+k] = min(dp[i+k], dp[i]+abs(h[i]-h[i+k]));
    }
  }
  int ans = dp[N-1];
  cout << ans << endl;
  return 0;
}