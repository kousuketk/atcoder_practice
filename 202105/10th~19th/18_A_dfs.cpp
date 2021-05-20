#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using Graph = vector<vector<int>>;

int h, w;

void dfs(const vector<vector<int>> &road, int i, int j, vector<vector<int>> &visited) {
  visited.at(i).at(j) = 1;
  // 上について, (i-1, j)
  if((i-1 >= 0) && (road.at(i-1).at(j) == 1) && (visited.at(i-1).at(j) == 0)) {
    dfs(road, i-1, j, visited);
  }
  // 下について, (i+1, j)
  if((i+1 < h) && (road.at(i+1).at(j) == 1) && (visited.at(i+1).at(j) == 0)) {
    dfs(road, i+1, j, visited);
  }
  // 右について, (i, j+1)
  if((j+1 < w) && (road.at(i).at(j+1) == 1) && (visited.at(i).at(j+1) == 0)) {
    dfs(road, i, j+1, visited);
  }
  // 左について, (i, j-1)
  if((j-1 >= 0) && (road.at(i).at(j-1) == 1) && (visited.at(i).at(j-1) == 0)) {
    dfs(road, i, j-1, visited);
  }
}

int main() {
  int sh, sw, gh, gw;
  cin >> h >> w;
  vector<vector<int>> road(h, vector<int>(w));
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      char c;
      cin >> c;
      if(c == 's') {
        sh = i; 
        sw = j;
      }
      if(c == 'g') {
        gh = i;
        gw = j;
      }
      if(c == '#') road.at(i).at(j) = 0;
      else road.at(i).at(j) = 1;
    }
  }
  vector<vector<int>> visited(h, vector<int>(w, 0));
  dfs(road, sh, sw, visited);
  if(visited.at(gh).at(gw)) cout << "Yes" << endl;
  else cout << "No" << endl;
}