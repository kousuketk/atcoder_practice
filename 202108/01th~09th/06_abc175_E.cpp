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

int H, W, K;
ll dp[3010][3010][4]; // (i,j)に行く上で、拾うアイテム価値の最大値
ll item[3010][3010];

ll rec(int h, int w, int count) {
  if(dp[h][w][count] != -1) return dp[h][w][count];
  if(h == H-1 && w == W-1) {
    if(count < 3) return item[h][w];
    else return 0;
  }
  ll res = 0;
  if(item[h][w] > 0 && count < 3) {
    // 自分を入れることができる時
    if(w+1 < W) res = max(res, rec(h, w+1, count+1)+item[h][w]);  // 自分を入れて右に行く
    if(h+1 < H) res = max(res, rec(h+1, w, 0)+item[h][w]);
  }
  if(w+1 < W) res = max(res, rec(h, w+1, count));
  if(h+1 < H) res = max(res, rec(h+1, w, 0));
  return dp[h][w][count] = res;
}

int main() {
  cin >> H >> W >> K;
  rep(i,K) {
    int r, c; cin >> r >> c;
    ll v; cin >> v;
    r--; c--;
    item[r][c] = v;
  }
  rep(i,3010)rep(j,3010)rep(k,4) dp[i][j][k] = -1;
  cout << rec(0,0,0) << endl;
}

// 最初dp[i][j]でやってたけどwaしていた
// →dp[i][j][count]でi行目のitemを入れた数をcountで持っておかないと
// countを含めた全探索ができない