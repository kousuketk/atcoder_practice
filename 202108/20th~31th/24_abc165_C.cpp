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

vector<int> buf;
Graph G;
int Q;
int ans = 0;
int range_start = 1;

void dfs(int i, int before_val, int size, int range_end) {
  if (i == size) {
    int sum = 0;
    rep(i,Q) {
      int a = G[i][0];
      int b = G[i][1];
      int c = G[i][2];
      int d = G[i][3];
      if(buf[b]-buf[a] == c) sum += d;
    }
    ans = max(ans, sum);
  } else {
    for(int j = before_val; j <= range_end; ++j) {
      buf[i] = j;
      dfs(i+1, j, size, range_end);
    }
  }
}

int main() {
  int N, M; cin >> N >> M >> Q;
  buf.resize(N);
  G.resize(Q);
  rep(i,Q) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    a--, b--;
    G[i].push_back(a), G[i].push_back(b), G[i].push_back(c), G[i].push_back(d);
  }
  dfs(0, 1, N, M);
  cout << ans << endl;
}