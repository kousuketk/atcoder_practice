#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const ll INF = 1100100100100100100;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

ll dp[410][410];
vector<ll> vec;
vector<ll> S;

ll rec(int l, int r) {
  if(dp[l][r] != -1) return dp[l][r];
  if(l == r) return 0;

  ll res = INF;
  // midで見ていって、左端or右端を+したときの最小値
  for(int mid = l; mid <= r-1; mid++) {
    res = min(res, rec(l, mid) + rec(mid+1, r) + S[r+1] - S[l]); // ここでa[l]~a[r]の和
  }
  return dp[l][r] = res;
}

int main() {
  int N; cin >> N;
  vec.resize(N);
  S.resize(N+1);
  rep(i,410) rep(j,410) dp[i][j] = -1;
  rep(i,N) cin >> vec[i];
  rep(i,N) S[i+1] = S[i] + vec[i];
  cout << rec(0, N-1) << endl;
}

// 何個かwa、以下通らない
// 6
// 7 6 8 6 1 1
// →rec(l,mid)にしたら通った
// 類題：https://atcoder.jp/contests/abc217/tasks/abc217_f