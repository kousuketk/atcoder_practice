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

int main() {
  ll N, M; cin >> N >> M;
  vector<P> vec(M);
  rep(i,M) {
    int a, b; cin >> a >> b;
    a--, b--;
    vec[i] = P(a, b);
  }
  vector<ll> ans;
  ll tmp_ans = N*(N-1)/2;
  ans.push_back(tmp_ans);
  UnionFind tree(N);
  for(int i = M-1; i > 0; i--) {
    int a = vec[i].first;
    int b = vec[i].second;
    // a, bが同じだったらスルー、違かったらsizeをかけ合わせて引く
    if(!tree.same(a, b)) {
      tmp_ans -= tree.size(a) * tree.size(b);
      tree.unite(a, b);
    }
    ans.push_back(tmp_ans);
  }
  reverse(ALL(ans));
  rep(i,M) cout << ans[i] << endl;
  return 0;
}