#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i=0; i < int(n); i++)

struct UnionFind
{
  vector<int> par;

  UnionFind(int N) : par(N) {
    for(int i = 0; i < N; i++) par[i] = i;
  }

  int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;
    par[rx] = ry;
  }

  bool same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

struct Edge
{
  int a, b, cost;

  // コストの大小で順序定義
  bool operator<(const Edge& o) const {
    return cost < o.cost;
  }
};

// 頂点数と辺集合の組として定義したグラフ
struct Graph
{
  int n;
  vector<Edge> es;

  // クラスカル法で無向最小全域木のコストの和を計算する
  // グラフが非連結のときは最小全域森のコストの和となる
  int kruskal() {
    // コストが小さい順にソート
    sort(es.begin(), es.end());

    UnionFind tree(n);
    int min_cost = 0;

    // for(Edge& e : es) {} でもできそう
    rep(ei, es.size()) {
      Edge& e = es[ei];
      // 連結していなかったら連結してコストを追加する
      if (!tree.same(e.a, e.b)) {
        min_cost += e.cost;
        tree.unite(e.a, e.b);
      }
    }
    return min_cost;
  }
};

Graph input_graph() {
  Graph g;
  int m;
  cin >> g.n >> m;
  rep(i, m) {
    Edge e;
    cin >> e.a >> e.b >> e.cost;
    g.es.push_back(e);
  }
  return g;
}

int main()
{
  Graph g = input_graph();
  cout << "最小全域木のコスト: " << g.kruskal() << endl;
  return 0;
}