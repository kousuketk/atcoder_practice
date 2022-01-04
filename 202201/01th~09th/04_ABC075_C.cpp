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
  vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

  UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
    for(int i = 0; i < N; i++) par[i] = i;
  }

  int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y) { // xとyの木を併合
    int rx = root(x); //xの根をrx
    int ry = root(y); //yの根をry
    if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
    par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
  }

  bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main() {
  int N, M; cin >> N >> M;
  vector<P> vec(M);
  rep(i,M) {
    int a, b; cin >> a >> b;
    a--, b--;
    vec[i] = P(a, b);
  }
  int ans = 0;
  rep(i,M) {
    UnionFind tree(N);  // i番目以外の辺をつなぐ
    rep(j,M) {
      if(j == i) continue;
      int a = vec[j].first;
      int b = vec[j].second;
      tree.unite(a, b);
    }
    int c = vec[i].first;
    int d = vec[i].second;
    if(!tree.same(c, d)) ans++;
  }
  cout << ans << endl;
}