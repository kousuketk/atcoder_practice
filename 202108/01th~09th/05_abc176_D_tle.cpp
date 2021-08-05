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

int H, W, sh, sw, gh, gw;
vector<string> road;
int dp[1010][1010];

void rec(int h, int w, int count) {
  if(dp[h][w] != -1 && dp[h][w] <= count) return;
  dp[h][w] = count;

  // 移動A
  rep(i,4) {
    // 範囲内にあり, 壁でない
    if(h+next_h[i] >= 0 && h+next_h[i] < H &&
      w+next_w[i] >= 0 && w+next_w[i] < W &&
      road[h+next_h[i]][w+next_w[i]] != '#') {
        rec(h+next_h[i], w+next_w[i], count);
    }
  }

  // 移動B
  for(int i = -2; i <= 2; i++) {
    for(int j = -2; j <= 2; j++) {
      if(h+i >= 0 && h+i < H &&
        w+j >= 0 && w+j < W &&
        road[h+i][w+j] != '#') {
          rec(h+i, w+j, count+1);
        }
    }
  }
}

int main() {
  cin >> H >> W >> sh >> sw >> gh >> gw;
  sh--; sw--; gh--; gw--;
  road.resize(H);
  rep(i,H) cin >> road[i];
  rep(i,1010)rep(j,1010) dp[i][j] = -1;
  rec(sh, sw, 0);
  cout << dp[gh][gw] << endl;
}

// TLE...→幅優先探索でO(HW)で計算できる