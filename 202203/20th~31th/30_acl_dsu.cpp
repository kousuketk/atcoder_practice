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
struct UnionFind {
  vector<int> par;
  vector<int> siz;
  UnionFind(int N) : par(N), siz(N) {
    rep(i,N) par[i] = i, siz[i] = 1;
  }
  int root(int x) {
    if(par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  void unite(int x, int y) {
    int rx = root(x), ry = root(y);
    if(rx == ry) return;
    if(siz[rx] < siz[ry]) swap(rx, ry);
    siz[rx] += siz[ry];
    par[ry] = rx;
    return;
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  int size(int x) {
    return siz[root(x)];
  }
};


int main() {
  int N, Q; cin >> N >> Q;
  UnionFind uf(N);
  rep(i,Q) {
    int t, u, v; cin >> t >> u >> v;
    if(t == 0) {
      uf.unite(u, v);
    } else {
      bool flag = uf.same(u, v);
      if(flag) cout << 1 << endl;
      else cout << 0 << endl;
    }
  }
  return 0;
}