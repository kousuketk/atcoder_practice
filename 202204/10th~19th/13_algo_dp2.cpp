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

// 部分和数え上げ問題(jにできる組み合わせは何個あるか？)
int dp[105][10005];  // i番目まで見た時、jにすることができる個数
int main() {
  int N, M; cin >> N >> M;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  dp[0][0] = 1;
  rep(i,N) {
    rep(j,M+1) {
      dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % 1000;
      if(j-vec[i] >= 0) dp[i+1][j] = (dp[i+1][j] + dp[i][j-vec[i]]) % 1000;
    }
  }
  int ans = dp[N][M];
  cout << ans << endl;
  return 0;
}