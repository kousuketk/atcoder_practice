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

int main() {
  int N, M; cin >> N >> M;
  // 入力をuniqueにする
  vector<P> input(M);
  rep(i,M) cin >> input[i].first >> input[i].second;
  sort(ALL(input));
  input.erase(unique(ALL(input)), input.end());
  int size_input = input.size();
  // 内部処理開始
  Graph G(N);
  vector<int> deg(N, 0);
  rep(i,size_input) {
    int a = input[i].first;
    int b = input[i].second;
    a--; b--;
    G[a].push_back(b);
    deg[b]++; // 入次数
  }
  priority_queue<int, vector<int>, greater<int>> que;
  rep(i,N) if(deg[i] == 0) que.push(i);
  vector<int> ans;
  while(!que.empty()) {
    int v = que.top(); que.pop();
    ans.push_back(v);
    for(auto nv : G[v]) {
      deg[nv]--;
      if(deg[nv] == 0) que.push(nv);
    }
  }
  // すべての入次数が0でないとサイクル→"-1"
  bool flag = true;
  rep(i,N) if(deg[i] != 0) flag = false;
  if(flag) rep(i,N) cout << ans[i]+1 << " ";
  else cout << "-1";
  cout << endl;
}