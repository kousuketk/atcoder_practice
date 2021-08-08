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

ll dp[1100][1100]; // (i,j)へ行くためにワープの最低使用回数

int main() {
  int H, W; cin >> H >> W;
  int sh, sw, gh, gw; cin >> sh >> sw >> gh >> gw;
  sh--; sw--; gh--; gw--;
  vector<string> mass(H);
  rep(i,H) cin >> mass[i];
  // 初期設定
  rep(i,1100)rep(j,1100) dp[i][j] = -1;
  queue<P> que;
  dp[sh][sw] = 0;
  que.push({sh, sw}); // que.emplace(sh, sw)
  int count = 0;
  while(!que.empty()) {
    queue<P> que2;
    while(!que.empty()) {
      P tmp = que.front(); que.pop();
      int h = tmp.first;
      int w = tmp.second;
      // 上下左右を調べる(範囲内にあり、壁でない)
      rep(i,4) {
        if(h+next_h[i] >= 0 && h+next_h[i] < H &&
          w+next_w[i] >= 0 && w+next_w[i] < W &&
          mass[h+next_h[i]][w+next_w[i]] != '#') {
            if(dp[h+next_h[i]][w+next_w[i]] != -1) continue;
            dp[h+next_h[i]][w+next_w[i]] = dp[h][w];
            que.push({h+next_h[i], w+next_w[i]});
        }
      }
      // 移動Bを調べる
      for(int i = -2; i <= 2; i++) {
        for(int j = -2; j <= 2; j++) {
          if(h+i >= 0 && h+i < H &&
            w+j >= 0 && w+j < W &&
            mass[h+i][w+j] != '#' && dp[h+i][w+j] == -1) {
              que2.push({h+i, w+j});
            }
        }
      }
    }
    while(!que2.empty()) {
      P tmp = que2.front(); que2.pop();
      int h = tmp.first;
      int w = tmp.second;
      // h, wについて新しく更新できるのであれば、queに追加する
      if(dp[h][w] != -1) continue;
      dp[h][w] = count+1;
      que.push({h, w});
    }
    count++;
  }
  cout << dp[gh][gw] << endl;
}