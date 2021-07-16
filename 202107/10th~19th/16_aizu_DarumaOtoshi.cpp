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
int dp[310][310];

int dfs(int l, int r) {
  if(dp[l][r] != -1) return dp[l][r];
  if(l >= r) return 0;
  if(l == r-1) {
    if(abs(vec[l]-vec[r])<=1) return 2;
    else return 0;
  }

  int res = 0;
  // l,rの範囲をごっそり取れる？→取れなかったら、i番目を見ていく
  if(abs(vec[l]-vec[r])<=1 && dfs(l+1,r-1)==r-l-1) {
    res = max(res, r-l+1);
  } else {
    // ごっそり取れなかったら1個ずつ見ていく
    for(int i = l; i < r; i++) {
      res = max(res, dfs(l, i) + dfs(i+1, r));
    }
  }

  return dp[l][r] = res;
}

int main() {
  int N; cin >> N;
  while(N != 0) {
    vec.resize(N);
    rep(i,N) cin >> vec[i];
    rep(i,310) rep(j,310) dp[i][j] = -1;
    cout << dfs(0, N-1) << endl;
    cin >> N;
  }
}
