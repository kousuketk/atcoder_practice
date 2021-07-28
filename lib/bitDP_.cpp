#include <iostream>
#include <bitset>
using namespace std;

const int INF = 100000000;

int N;
int dist[21][21];

int dp[(1<<20) + 1][21];
int rec(int bit, int v)
{
  if (dp[bit][v] != -1) return dp[bit][v];

  if (bit == (1<<v)) {
    return dp[bit][v] = 0;
  }

  int res = INF;
  int prev_bit = bit & ~(1<<v);

  // v の手前のノードとして u を全探索
  for (int u = 0; u < N; ++u) {
    if (!(prev_bit & (1<<u))) continue;
    res = min(res, rec(prev_bit, u) + dist[u][v]);
  }

  return dp[bit][v] = res;
}

int main()
{
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> dist[i][j];
    }
  }

  for (int bit = 0; bit < (1<<N); ++bit) for (int v = 0; v < N; ++v) dp[bit][v] = -1;

  int res = INF;
  for (int v = 0; v < N; ++v) {
    res = min(res, rec((1<<N)-1, v));
  }
  cout << res << endl;
}

// https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361#11-bit-dp