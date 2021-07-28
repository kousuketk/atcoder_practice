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

int mass[2000][2000];

int main() {
  int H, W, N, M; cin >> H >> W >> N >> M;
  rep(i,N) {
    int a, b; cin >> a >> b;
    a--; b--;
    mass[a][b] = 1  ;  // 電球のマス
  }
  rep(i,M) {
    int c, d; cin >> c >> d;
    c--; d--;
    mass[c][d] = -1; // 壁のマス
  }
  // 左から光を当てる:2
  rep(i,H) rep(j,W) {
    if(j == 0) continue;
    if(mass[i][j] == 1) continue;  // 電球だったら無視
    if(mass[i][j] == -1) continue; // 壁だったら遮る
    if(mass[i][j-1] == 1 || mass[i][j-1] == 2) mass[i][j] = 2;
  }
  // 右から光を当てる:3
  rep(i,H) rep(j,W) {
    if(j == 0) continue;
    if(mass[i][W-1-j] == 1) continue;  // 電球だったら無視
    if(mass[i][W-1-j] == -1) continue; // 壁だったら遮る
    if(mass[i][W-1-j+1] == 1 || mass[i][W-1-j+1] == 3) mass[i][W-1-j] = 3;
  }
  // 上から光を当てる:4
  rep(i,H) rep(j,W) {
    if(i == 0) continue;
    if(mass[i][j] == 1) continue;  // 電球だったら無視
    if(mass[i][j] == -1) continue; // 壁だったら遮る
    if(mass[i-1][j] == 1 || mass[i-1][j] == 4) mass[i][j] = 4;
  }
  // 下から光を当てる:5
  rep(i,H) rep(j,W) {
    if(i == 0) continue;
    if(mass[H-1-i][j] == 1) continue;  // 電球だったら無視
    if(mass[H-1-i][j] == -1) continue; // 壁だったら遮る
    if(mass[H-1-i+1][j] == 1 || mass[H-1-i+1][j] == 5) mass[H-1-i][j] = 5;
  }
  // 最後にブロック以外で、光が届く数を出力
  int ans = 0;
  rep(i,H) rep(j,W) {
    if(mass[i][j] > 0) ans++;
  }
  cout << ans << endl;
}