#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using Graph = vector<vector<int>>;

int w, h;
vector<vector<int>> road;
vector<vector<bool>> seen;

void dfs(int i, int j) {
  seen[i][j] = true;
  // 上について、(i-1, j)
  if((i-1 >= 0) && (road[i-1][j] == 1) && !seen[i-1][j]) {
    dfs(i-1, j);
  }
  // 下について、(i+1, j)
  if((i+1 < h) && (road[i+1][j] == 1) && !seen[i+1][j]) {
    dfs(i+1, j);
  }
  // 右について、(i, j+1)
  if((j+1 < w) && (road[i][j+1] == 1) && !seen[i][j+1]) {
    dfs(i, j+1);
  }
  // 左について、(i, j-1)
  if((j-1 >= 0) && (road[i][j-1] == 1) && !seen[i][j-1]) {
    dfs(i, j-1);
  }
  // 上左について、(i-1, j-1)
  if((i-1 >= 0) && (j-1 >= 0) && (road[i-1][j-1] == 1) && !seen[i-1][j-1]) {
    dfs(i-1, j-1);
  }
  // 上右について、(i-1, j+1)
  if((i-1 >= 0) && (j+1 < w) && (road[i-1][j+1] == 1) && !seen[i-1][j+1]) {
    dfs(i-1, j+1);
  }
  // 下左について、(i+1, j-1)
  if((i+1 < h) && (j-1 >= 0) && (road[i+1][j-1] == 1) && !seen[i+1][j-1]) {
    dfs(i+1, j-1);
  }
  // 下右について、(i+1, j+1)
  if((i+1 < h) && (j+1 < w) && (road[i+1][j+1] == 1) && !seen[i+1][j+1]) {
    dfs(i+1, j+1);
  }
}

int main() {
  cin >> w >> h;
  road.resize(h);
  seen.resize(h);
  rep(i,h) {
    road.at(i).resize(w);
    seen.at(i).resize(w);
  }
  rep(i,h)rep(j,w) {
    cin >> road[i][j];
  }
  int count = 0;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(seen[i][j]) continue;
      if(road[i][j] == 0) continue;
      dfs(i, j);
      count++;
    }
  }
  cout << count << endl;
}