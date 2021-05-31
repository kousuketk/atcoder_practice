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

int main() {
  int N, Q;
  cin >> N >> Q;
  Graph G(N);
  for(int i = 0; i < N-1; i++) {
    int a, b;
    cin >> a >> b;
    G[a-1].push_back(b-1);
  }
  vector<int> count(N, 0);
  for(int i = 0; i < Q; i++) {
    int p, x;
    cin >> p >> x;
    p--;
    count[p] += x;
  }
  // vector<int> ans(N, 0);
  // i番目の頂点について、G[i]の全ての要素を+count[i]する
  // G[i]を0~N-1全探索、G[i]の全ての要素に対してans[i] += count[i]する
  for(int i = 0; i < N; i++) {
    for(int next_i : G[i]) {
      count[next_i] += count[i];
    }
  }
  printVec(count);
}

// 親に近いほうが入力が小さいことではなかったからwaだった。(有向木では解けない)
// dfsで行きがけ順に探索すれば、有向無向関係なく上から順番に探索される