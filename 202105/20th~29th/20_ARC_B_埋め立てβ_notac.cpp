#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using Graph = vector<vector<int>>;

int h = 10;
int w = 10;
int count_circle = 0;
int sum_connected = 0;
vector<vector<int>> road;
vector<vector<int>> seen;

void dfs(int i, int j) {
  int count_connect = 0;
  seen[i][j] = true;
  // 上について、(i-1, j)
  if((i-1 >= 0) && (road[i-1][j] == 1) && !seen[i-1][j]) {
    sum_connected++;
    dfs(i-1, j);
  }
  // 下について、(i+1, j)
  if((i+1 < h) && (road[i+1][j] == 1) && !seen[i+1][j]) {
    sum_connected++;
    dfs(i+1, j);
  }
  // 右について, (i, j+1)
  if((j+1 < w) && (road[i][j+1] == 1) && !seen[i][j+1]) {
    sum_connected++;
    dfs(i, j+1);
  }
  // 左について, (i, j-1)
  if((j-1 >= 0) && (road[i][j-1] == 1) && !seen[i][j-1]) {
    sum_connected++;
    dfs(i, j-1);
  }
  if(count_connect == 0) {
    // 上について、(i-1, j)
    if(i-1 >= 0) {
      count_connect++;
      road[i-1][j] == 1;
      seen[i-1][j] == true;
      dfs(i-1, j);
      road[i-1][j] == 0;
      seen[i-1][j] == false;
      count_connect--;
    }
    // 下について、(i+1, j)
    if(i+1 < h) {
      count_connect++;
      road[i+1][j] == 1;
      seen[i+1][j] == true;
      dfs(i+1, j);
      road[i+1][j] == 0;
      seen[i+1][j] == false;
      count_connect--;
    }
    // 右について、(i, j+1)
    if(j+1 < w) {
      count_connect++;
      road[i][j+1] == 1;
      seen[i][j+1] == true;
      dfs(1, j+1);
      road[i][j+1] == 0;
      seen[i][j+1] == false;
      count_connect--;
    }
    // 左について、(i, j-1)
    if(j-1 >= 0) {
      count_connect++;
      road[i][j-1] == 1;
      road[i][j-1] == true;
      dfs(1, j-1);
      road[i][j-1] == 0;
      road[i][j-1] == false;
      count_connect--;
    }
  }
}

int main() {
  road.resize(h);
  seen.resize(h);
  rep(i,h) {
    road.at(i).resize(w);
    seen.at(i).resize(w);
  }
  rep(i,h) {
    string s;
    cin >> s;
    rep(j,w) {
      if(s[j] == 'x') {
        road[i][j] = 0;
      } else if(s[j] == 'o') {
        road[i][j] = 1;
        count_circle++;
      } else {
        cout << "input error" << endl;
      }
    }
  }
  int tmp_count = 0;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(tmp_count >= 1) {
        if(count_circle == sum_connected) {
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
        return 0;
      }
      if(road[i][j] == 0) continue;
      sum_connected++;
      tmp_count++;
      dfs(i,j);
    }
  }
  cout << "NO" << endl;
}