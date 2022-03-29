#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int N, M; cin >> N >> M;
  Graph G(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<int> dist(N, -1);
  queue<int> que;
  int count = 0;
  for (int v = 0; v < N; ++v) {
    if (dist[v] != -1) continue; // v が探索済みならスルー
    dist[v] = 0, que.push(v);
    while (!que.empty()) {
      int v = que.front(); que.pop();
      for (auto nv : G[v]) {
        if (dist[nv] == -1) {
          dist[nv] = dist[v] + 1;
          que.push(nv);
        }
      }
    }
    ++count;
  }
  cout << count << endl;
}