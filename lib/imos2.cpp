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


// for (int y = 0; y < H; y++) {
//   for (int x = 0; x < W; x++) {
//     tiles[y][x] = 0;
//   }
// }
// for (int i = 0; i < N; i++) {
//   // モンスター i が現れる [(A[i],C[i]), (B[i],D[i])) の範囲に 1 を足す
//   for (int y = C[i]; y < D[i]; y++) {
//     for (int x = A[i]; x < B[i]; x++) {
//       tiles[y][x]++;
//     }
//   }
// }
// // 最大値を調べる
// int tile_max = 0;
// for (int y = 0; y < H; y++) {
//   for (int x = 0; x < W; x++) {
//     if (tile_max < tiles[y][x]) {
//       tile_max = tiles[y][x];
//     }
//   }
// }

for (int y = 0; y < H; y++) {
  for (int x = 0; x < W; x++) {
    tiles[y][x] = 0;
  }
}
// 重みの加算 (図 3)
for (int i = 0; i < N; i++) {
  tiles[C[i]][A[i]]++;
  tiles[C[i]][B[i]]--;
  tiles[D[i]][A[i]]--;
  tiles[D[i]][B[i]]++;
}
// 横方向への累積和 (図 4, 5)
for (int y = 0; y < H; y++) {
  for (int x = 1; x < W; x++) {
    tiles[y][x] += tiles[y][x - 1];
  }
}
// 縦方向の累積和 (図 6, 7)
for (int y = 1; y < H; y++) {
  for (int x = 0; x < W; x++) {
    tiles[y][x] += tiles[y - 1][x];
  }
}
// 最大値を調べる
int tile_max = 0;
for (int y = 0; y < H; y++) {
  for (int x = 0; x < W; x++) {
    if (tile_max < tiles[y][x]) {
      tile_max = tiles[y][x];
    }
  }
}