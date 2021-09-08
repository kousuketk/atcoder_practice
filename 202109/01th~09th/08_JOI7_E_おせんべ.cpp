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

int main() {
  int R, C; cin >> R >> C;
  Graph G(R);
  rep(i,R) {
    rep(j,C) {
      int tmp; cin >> tmp;
      G[i].push_back(tmp);
    }
  }
  int ans = 0;
  for(int tmp = 0; tmp < (1<<R); tmp++) {
    bitset<10> bit(tmp);

    // 初期化
    Graph G_tmp(R);
    rep(i,R) {
      rep(j,C) {
        int tmp_g = G[i][j];
        G_tmp[i].push_back(tmp_g);
      }
    }

    for(int i = 0; i < R; i++) {
      if(bit.test(i)) { // i行目をひっくり返す
        rep(j,C) {
          G_tmp[i][j] = G_tmp[i][j]*(-1) + 1;
        }
      }
    }
    // C列見ていく
    int cnt = 0;
    rep(i,C) {
      int cnt_white = 0;
      int cnt_black = 0;
      rep(j,R) {
        if(G_tmp[j][i] == 0) cnt_white++;
        if(G_tmp[j][i] == 1) cnt_black++;
      }
      cnt += max(cnt_white, cnt_black);
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}