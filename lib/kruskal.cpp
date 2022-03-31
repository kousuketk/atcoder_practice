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

struct Edge {
  int cost, a, b;

  bool operator<(const Edge& o) const {
    return cost < o.cost;
  }
};

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

int main()
{
  int N, M; cin >> N >> M;
  vector<Edge> E(M);
  rep(i,M) {
    int a, b, cost; cin >> a >> b >> cost;
    E[i] = Edge{cost, a, b};
  }
  UnionFind tree(N);
  sort(E.begin(), E.end());
  int min_cost = 0;
  for(Edge& e : E) {
    if (!tree.same(e.a, e.b)) {
      tree.unite(e.a, e.b);
      min_cost += e.cost;
    }
  }
  cout << min_cost << endl;
  return 0;
}

// グラフは連結であることを仮定している。 
// グラフが連結でない場合、連結成分数が最大の最小全域森が求まる