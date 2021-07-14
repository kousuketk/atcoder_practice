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
int dp[(1<<20) + 1][21]; // dpテーブルは余裕をもったサイズにする
vector<vector<int>> G;

int rec(int start, int bit, int v)
{
  // すでに探索済みだったらリターン
  if (dp[bit][v] != -1) return dp[bit][v];

  // 部分集合が最後だったら、startとのコストを出してreturn
  if (bit == (1<<v)) {
    return dp[bit][v] = dist[start][v];
  }

  // 答えを格納する変数
  int res = INF;

  // bit の v を除いたもの
  int prev_bit = bit & ~(1<<v);

  // v の手前のノードとしてG[v]を全探索
  for(int nv : G[v]) {
    if (!(prev_bit & (1<<nv))) continue; // e.to が prev_bit になかったらダメ

    // 再帰的に探索
    res = min(res, rec(start, prev_bit, nv) + dist[nv][v]);
  }

  return dp[bit][v] = res; // メモしながらリターン
}

int main()
{
  // 入力
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

  // テーブルを全部 -1 にしておく (-1 でなかったところは探索済)
  for (int bit = 0; bit < (1<<N); ++bit) for (int v = 0; v < N; ++v) dp[bit][v] = -1;

  // 探索
  int res = INF;
  for (int v = 0; v < N; ++v) {
    res = min(res, rec(v, (1<<N)-1, v));
  }
  if(res >= INF) cout << "-1" << endl;
  else cout << res << endl;
}