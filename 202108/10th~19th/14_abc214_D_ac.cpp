#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<ll,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;

struct UnionFind {
  vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
  vector<ll> size_vec;

  UnionFind(int N) : par(N), size_vec(N) { //最初は全てが根であるとして初期化
    for(int i = 0; i < N; i++) {
      par[i] = i;
      size_vec[i] = 1;
    }
  }

  int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y) { // xとyの木を併合
    int rx = root(x); //xの根をrx
    int ry = root(y); //yの根をry
    if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
    int tmp = size_vec[rx];
    size_vec[rx] += size_vec[ry]; // rootを見ないとsize_vecは正しくない
    size_vec[ry] += tmp;
    par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
  }

  bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }

  ll size(int x) {
    return size_vec[root(x)]; // rootを見ないとsize_vecは正しくないためrootを設定
  }
};


// 辺の重さでソートして、小さい方からUnionFindでつなげていきコストを計算していく(常にパスの最大値がわかる)
// 辺の重さでソートして、そのまま計算しちゃうと森の状態から木になるときの計算がうまく行かない
int main() {
  int N; cin >> N;
  vector<T> vec(N-1);
  rep(i,N-1) {
    int u, v; cin >> u >> v;
    ll w; cin >> w;
    u--; v--;
    vec[i] = T(w, u, v);
  }
  sort(ALL(vec));
  UnionFind tree(N);
  ll ans = 0;
  rep(i,N-1) {
    ll w = get<0>(vec[i]);
    int u = get<1>(vec[i]);
    int v = get<2>(vec[i]);
    ll count = tree.size(u)*tree.size(v);  // (ll)tree.size(u)*tree.size(v);でも行ける
    ans += count*w;
    tree.unite(u, v);
  }
  cout << ans << endl;
}