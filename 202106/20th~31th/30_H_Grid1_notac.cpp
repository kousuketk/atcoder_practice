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

ll memo[1010][1010];
bool seen[1010][1010];
vector<string> grid;
ll H, W;
ll waru = 1000000000 + 7;

ll rec(ll i, ll j) {
  if(seen[i][j]) return memo[i][j];
  seen[i][j] = true;
  if(i == H-1 && j == W-2) return memo[i][j] == 1;  // =
  if(i == H-2 && j == W-1) return memo[i][j] == 1;  // =
  ll res = 0;
  // 右に行く
  if(grid[i][j+1] != '#' && j+1 < W) { // j+1 < Wを先に比較する. grid[i][j+1]を先に見てしまうと, grid外を見たときにエラーとなる.
    res = (res + rec(i, j+1)) % waru;
  }
  // 下に行く
  if(grid[i+1][j] != '#' && i+1 < H) { // i+1 < Hを先に比較する. grid[i+1][j]を先に見てしまうと, grid外を見たときにエラーとなる.
    res = (res + rec(i+1, j)) % waru;
  }
  return memo[i][j] = res;
}

int main() {
  cin >> H >> W;
  grid.resize(H);
  rep(i,H) cin >> grid[i];
  cout << rec(0,0) << endl;
}