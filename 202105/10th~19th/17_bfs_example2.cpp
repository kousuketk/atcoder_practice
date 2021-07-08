#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using Graph = vector<vector<int>>;

int main() {
  int r, c, sy, sx, gy, gx;
  cin >> r >> c >> sy >> sx >> gy >> gx;
  vector<vector<int>> road(r, vector<int>(c));
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      char c;
      cin >> c;
      if(c == '#') road.at(i).at(j) = 0;
      else if(c == '.') road.at(i).at(j) = 1;
    }
  }

  queue<int> que;
  vector<vector<int>> dist(r, vector<int>(c, -1));
  que.push(sy-1);
  que.push(sx-1);
  dist.at(sy-1).at(sx-1) = 0;
  while (!que.empty()) {
    int x = que.front();
    que.pop();
    int y = que.front();
    que.pop();

    // まず上について, (x-1, y)
    if((x-1 > 0) && (road.at(x-1).at(y) == 1) && (dist.at(x-1).at(y) == -1)) {
      dist.at(x-1).at(y) = dist.at(x).at(y) + 1;
      que.push(x-1);
      que.push(y);
    }
    // 下, (x+1, y)
    if((x+1 < r) && (road.at(x+1).at(y) == 1) && (dist.at(x+1).at(y) == -1)) {
      dist.at(x+1).at(y) = dist.at(x).at(y) + 1;
      que.push(x+1);
      que.push(y);
    }
    // 右, (x, y+1)
    if((y+1 < c) && (road.at(x).at(y+1) == 1) && (dist.at(x).at(y+1) == -1)) {
      dist.at(x).at(y+1) = dist.at(x).at(y) + 1;
      que.push(x);
      que.push(y+1);
    }
    // 左, (x, y-1)
    if((y-1 > 0) && (road.at(x).at(y-1) == 1) && (dist.at(x).at(y-1) == -1)) {
      dist.at(x).at(y-1) = dist.at(x).at(y) + 1;
      que.push(x);
      que.push(y-1);
    }
  }
  cout << dist.at(gy-1).at(gx-1) << endl;
}