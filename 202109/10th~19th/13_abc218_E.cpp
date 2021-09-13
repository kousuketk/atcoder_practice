#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};
 
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
 
int main() {
  int N, M; cin >> N >> M;
  vector<Edge> E(M);
  rep(i,M) {
    int a, b, c; cin >> a >> b >> c;
    a--, b--;
    E[i] = Edge{c, a, b};
  }
  UnionFind tree(N);
  sort(E.begin(), E.end());
  ll reward = 0;
  for(Edge& e : E) {
    if(!tree.same(e.a, e.b)) {
      tree.unite(e.a, e.b);
    } else {
      if(e.cost > 0) reward += e.cost;
    }
  }
  cout << reward << endl;
}
 
// Edgeを小さい方から
// tree.same(同じ)だったら、受け取れる(がマイナスだったら受け取らない)