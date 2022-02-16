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
  int N, K, L; cin >> N >> K >> L;
  vector<P> road(K);
  vector<P> train(L);
  rep(i,K) {
    cin >> road[i].first >> road[i].second;
    road[i].first--, road[i].second--;
  }
  rep(i,L) {
    cin >> train[i].first >> train[i].second;
    train[i].first--, train[i].second--;
  }
  UnionFind uf_road(N);
  UnionFind uf_train(N);
  // 1. それぞれ全ての通路をuniteする→o(M)
  // 2. 全部の頂点を見て、(uf_road.root(i), uf_train.root(i))で、mapを作成して+1していく→o(N)
  // 3. それぞれの頂点を見ていって、mapのuf_road.root(i), uf_train.root(i)を出力する(i番目から共通して行ける頂点数)
  // ----------------------------------------------------
  // 1.
  rep(i,K) {
    int x = road[i].first, y = road[i].second;
    uf_road.unite(x, y);
  }
  rep(i,L) {
    int x = train[i].first, y = train[i].second;
    uf_train.unite(x, y);
  }
  // 2.
  map<P, int> mp;
  rep(i,N) {
    int road = uf_road.root(i), train = uf_train.root(i);
    mp[{road, train}]++;
  }
  // 3.
  rep(i,N) {
    int road = uf_road.root(i), train = uf_train.root(i);
    int ans = mp[{road, train}];
    cout << ans << " ";
  }
  return 0;
}