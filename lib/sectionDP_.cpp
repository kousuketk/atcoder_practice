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

int w[310];
int dp[310][310];  // 区間[l, r)において、取り除ける最大個数

int rec(int l,int r){
  if(dp[l][r] != -1) return dp[l][r];

  if(abs(l - r) <= 1) return 0;

  int res = 0;
  if(abs(w[l] - w[r - 1]) <= 1 && rec(l + 1,r - 1) == r - l - 2)  // 差が1以下かつその間のブロックを全部取り除ける時
  {
    res = r - l;
  }

  for(int mid = l + 1;mid <= r - 1;mid++)
  {
    res = max(res , rec(l,mid) + rec(mid,r));
  }
  return dp[l][r] = res;
};

int main() {
  while(true) {
    int N; cin >> N;
    if(N == 0) break;
    rep(i,310) w[i] = 0;
    rep(i,310) rep(j,310) dp[i][j] = -1;
    rep(i,N) cin >> w[i];
    int ans = rec(0, N);
    cout << ans << endl;
  }
  return 0;
}

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1611&lang=jp