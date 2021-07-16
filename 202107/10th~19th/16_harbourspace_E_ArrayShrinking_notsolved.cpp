#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
// const ll INF = 1100100100100100100;
const int INF = 1001001001;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

vector<int> vec;
int dp[510][510];

// 何回マッチさせたかの最大値
int dfs(int l, int r) {
  if(dp[l][r] != -1) return dp[l][r];
  if(l == r-1) {
    if(vec[l] == vec[r]) return 1;
    else return 0;
  }

  int res = INF;
  // 左端とmatchする, 右端とmatchする, しない
  // match条件：dfs(l+1, r)==1, どうやってmatchさせればいいの？
  // 何回マッチさせたかを持てばいい
  if(vec[l]==vec[r] && dfs(l+1, r-1)==1) {
    res = min(res, 1);
  }
}

int main() {
  int N; cin >> N;
  vec.resize(N);
  rep(i,N) cin >> vec[i];
  rep(i,510) rep(j,510) dp[i][j] = -1;
  cout << dfs(0, N-1) << endl;
}
