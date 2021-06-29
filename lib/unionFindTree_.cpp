#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

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
  int N, M;
  cin >> N >> M;
  vector<int> P(N);
  for(int i = 0; i < N; i++){
    cin >> P[i];
  }

  UnionFind tree(N);

  for(int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    tree.unite(x-1, y-1); // x-1の木とy-1の木を併合する
  }

  int cnt = 0;
  for(int i = 0; i < N; i++) {
    if (tree.same(i, P[i]-1)) { //iとP[i]-1が同じ木に属するなら，カウンタに1追加
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}