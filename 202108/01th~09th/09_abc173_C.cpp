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
  int H, W, K; cin >> H >> W >> K;
  vector<string> road(H);
  rep(i,H) cin >> road[i];
  int ans = 0;
  for(int i = 0; i < (1<<H); i++) {
    for(int j = 0; j < (1<<W); j++) {
      vector<string> road_cp(H);
      rep(tmp_i,H) road_cp[tmp_i] = road[tmp_i];
      bitset<6> bit_i(i);
      for(int h = 0; h < H; h++) {
        // h行目を赤(r)にしていく
        if(bit_i.test(h)) {
          rep(tmp_w,W) road_cp[h][tmp_w] = 'r';
        }
      }
      bitset<6> bit_j(j);
      for(int w = 0; w < W; w++) {
        // w列目を赤(r)にしていく
        if(bit_j.test(w)) {
          rep(tmp_h,H) road_cp[tmp_h][w] = 'r';
        }
      }
      // 赤にし終わったので、黒を数える
      int count = 0;
      rep(h,H)rep(w,W) {
        if(road_cp[h][w] == '#') count++;
      }
      if(count == K) ans++;
    }
  }
  cout << ans << endl;
}