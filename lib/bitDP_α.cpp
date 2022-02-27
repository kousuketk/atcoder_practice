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
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int N;
int dist[21][21];
int dp[(1<<20) + 1][21];
vector<vector<int>> G;

int rec(int bit, int v)
{
  if (dp[bit][v] != -1) return dp[bit][v];

  // 部分集合が最後だったら、v→0へのコストを出してreturn
  if (bit == (1<<v)) {
    return dp[bit][v] = dist[0][v]; // 最後に0→vへのコストを算出
  }

  int res = INF;
  int prev_bit = bit & ~(1<<v);

  // v の手前のノードとしてG[v]を全探索
  for(int nv : G[v]) {
    if (!(prev_bit & (1<<nv))) continue;
    res = min(res, rec(prev_bit, nv) + dist[nv][v]);
  }

  return dp[bit][v] = res;
}

int main()
{
  cin >> N;
  int M; cin >> M;
  G.resize(N);
  rep(i,21)rep(j,21) dist[i][j] = INF;
  // Gに対して、逆向きに有向グラフを張っていく
  rep(i,M) {
    int s, t, d;
    cin >> s >> t >> d;
    G[t].push_back(s);
    dist[s][t] = d;
  }

  for (int bit = 0; bit < (1<<N); ++bit) for (int v = 0; v < N; ++v) dp[bit][v] = -1;

  int res = INF;
  res = min(res, rec((1<<N)-1, 0));
  if(res == INF) cout << "-1" << endl;
  else cout << res << endl;
}

// ハミルトングラフ, ハミルトン経路であるから、どの頂点から出発しても答えは同じ
// 逆に「好きな都市から出発して、全ての都市を訪れる.」ような問題は、
// ハミルトングラフでないから(1辺が欠けたようなもの)、出発地の全通りで求めないといけない
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A&lang=ja