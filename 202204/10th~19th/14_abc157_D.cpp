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

// 友達候補関係, ブロック関係をUnionFindで持つ. 直接の友達の数はカウントしておく
// ブロック関係は友達候補関係から見つけてあったら取り除く
int main() {
  int N, M, K; cin >> N >> M >> K;
  UnionFind uf_fr(N);
  vector<int> cnt_fr(N);
  Graph G(N);  // ブロック関係
  rep(i,M) {
    int a, b; cin >> a >> b;
    a--, b--;
    cnt_fr[a]++;
    cnt_fr[b]++;
    uf_fr.unite(a, b);
  }
  rep(i,K) {
    int c, d; cin >> c >> d;
    c--, d--;
    G[c].push_back(d);
    G[d].push_back(c);
  }
  rep(i,N) {
    int cnt = uf_fr.size(i) - 1;  // 自分を引く
    cnt -= cnt_fr[i];  // 直接の友達を引く
    // 友達候補関係からブロック関係を引く
    for(int ni : G[i]) {
      if(uf_fr.same(i, ni)) cnt--;
    }
    if(i != 0) cout << " ";
    cout << cnt;
  }
  cout << endl;
  return 0;
}