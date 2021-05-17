#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using Graph = vector<vector<int>>;

int main() {
  int N, M, s, t;
  cin >> N >> M >> s >> t;
  Graph G(N);
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    G.at(a).push_back(b);
  }

  // データ構造
  queue<int> que;
  vector<int> dist(N, -1);
  // 初期条件
  que.push(s);
  dist.at(s) = 0;
  while(!que.empty()) {
    int v = que.front();
    que.pop();

    for(int nv: G.at(v)) {
      if(dist.at(nv) != -1) continue;
      dist.at(nv) = dist.at(v) + 1;
      que.push(nv);
    }
  }
  if(dist.at(t) > 0) cout << "yes" << endl;
  else cout << "no" << endl;
}