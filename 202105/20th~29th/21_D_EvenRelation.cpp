#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int, int>;
using Graph = vector<vector<int>>;

int N;
vector<vector<T>> tree;
vector<int> color;

void dfs(int v, int col) {
  color[v] = col;
  for(int i = 0; i < tree.at(v).size(); i++) {
    int next_v = get<1>(tree.at(v).at(i));
    if(color[next_v] != -1) continue;
    // 距離が偶数の時, dfs(next_v, col);
    // 距離が奇数の時, dfs(next_v, 1-col);
    int len = get<2>(tree.at(v).at(i));
    if(len%2 == 0) dfs(next_v, col);
    else dfs(next_v, 1-col);
  }
}

int main() {
  cin >> N;
  tree.resize(N);
  color.resize(N, -1);
  for(int i = 0; i < N; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    T tmp_a(a-1, b-1, c);
    tree[a-1].push_back(tmp_a);
    T tmp_b(b-1, a-1, c);
    tree[b-1].push_back(tmp_b);
  }
  dfs(0, 0);
  rep(i,N) {
    cout << color[i] << endl;
  }
}