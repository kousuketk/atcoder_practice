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

// K個以内部分和問題(K個以内の部分和で総和Mを作れるか？)
int dp[505][10005];
int main() {
  int N, M, K; cin >> N >> M >> K;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  rep(i,505) rep(j,10005) dp[i][j] = INF;
  dp[0][0] = 0;
  rep(i,N) {
    rep(j,M+1) {
      dp[i+1][j] = dp[i][j];
      if(j-vec[i]>=0) dp[i+1][j] = min(dp[i+1][j], dp[i][j-vec[i]]+1);
    }
  }
  int cnt = dp[N][M];
  if(cnt <= K) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}