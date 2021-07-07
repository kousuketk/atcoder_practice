#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int N;
vector<int> vec;
int dp[3000][3000];

ll rec(int l, int r, int turn) {
  if(dp[l][r] != -1) return dp[l][r];
  if(l == r) return 0;

  ll res = 0;
  if(turn == 1) {
    // 先頭, 末尾を取り除いて最大化
    res = max(rec(l+1, r, turn*(-1)) + vec[l], rec(l, r-1, turn*(-1)) + vec[r]);
  } else {
    // 先頭, 末尾を取り除いて最小化
    res = min(rec(l+1, r, turn*(-1)) + vec[l], rec(l, r-1, turn*(-1)) + vec[r]);
  }
  return dp[l][r] = res;
}

int main() {
  cin >> N;
  vec.resize(N);
  rep(i,N) {
    cin >> vec[i];
  }
  rep(i,3000) rep(j,3000) dp[i][j] = -1;
  cout << rec(0, N-1, 1);
}