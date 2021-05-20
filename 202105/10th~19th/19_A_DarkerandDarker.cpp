#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];
  int road[h][w];
  queue<P> que;
  int all_count = 0;
  rep(i,h)rep(j,w) {
    if(s[i][j] == '#') {
      road[i][j] = 1;
      P tmp(i,j);
      que.push(tmp);
      all_count++;
    } else {
      road[i][j] = 0;
    }
  }
  int reverse_count = 0;
  while(all_count != h*w) {
    vector<P> vec;
    while(!que.empty()) {
      P tmp = que.front();
      que.pop();
      int i = tmp.first;
      int j = tmp.second;
      // 上を黒にする
      if(i-1 >= 0 && road[i-1][j] == 0) {
        road[i-1][j] = 1;
        P tmp2(i-1,j);
        vec.push_back(tmp2);
        all_count++;
      }
      // 下を黒にする
      if(i+1 < h && road[i+1][j] == 0) {
        road[i+1][j] = 1;
        P tmp2(i+1,j);
        vec.push_back(tmp2);
        all_count++;
      }
      // 右を黒にする
      if(j+1 < w && road[i][j+1] == 0) {
        road[i][j+1] = 1;
        P tmp2(i,j+1);
        vec.push_back(tmp2);
        all_count++;
      }
      // 左を黒にする
      if(j-1 >= 0 && road[i][j-1] == 0) {
        road[i][j-1] = 1;
        P tmp2(i,j-1);
        vec.push_back(tmp2);
        all_count++;
      }
    }
    reverse_count++;
    if(vec.size() == 0) break;
    for(int i = 0; i < vec.size(); i++) {
      P tmp = vec[i];
      que.push(tmp);
    }
  }
  cout << reverse_count << endl;
}