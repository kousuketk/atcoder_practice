#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using Graph = vector<vector<int>>;
int inf = 100100100;

int h, w;
bool visited[2020][2020];
int memo[2020][2020];
int road[2020][2020];

int dp(int i, int j) {
  if(visited[i][j]) return memo[i][j];
  visited[i][j] = true;
  int turn = (i + j) % 2;
  if(i == h-1 && j == w-1) return memo[i][j] = 0;
  int res = -inf;
  if(turn == 0) {
    if(i+1 < h) res = max(memo[i][j], dp(i+1, j) + road[i+1][j]);
    if(j+1 < w) res = max(memo[i][j], dp(i, j+1) + road[i][j+1]);
    return memo[i][j] = res;
  } else {
    if(i+1 < h) res = min(memo[i][j], dp(i+1, j) - road[i+1][j]);
    if(j+1 < w) res = min(memo[i][j], dp(i, j+1) - road[i][j+1]);
    return memo[i][j] = res;
  }
}

int main() {
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];
  rep(i,h)rep(j,w) road[i][j] = s[i][j] == '+' ? 1 : -1;
  int score = dp(0,0);
  if(score > 0) cout << "Takahashi" << endl;
  else if(score == 0) cout << "Draw" << endl;
  else cout << "Aoki" << endl;
}