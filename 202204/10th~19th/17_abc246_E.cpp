#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using T = tuple<int,int,int>;
using P = pair<int,T>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
vector<int> next_i = {-1, 1, 1, -1};
vector<int> next_j = {1, 1, -1, -1};
vector<int> dir = {1, 2, 3, 4};

// dir：右上(1), 右下(2), 左下(3), 左上(4)
// どこから来たかを持っておく. dequeを使って同じ方向は前に、+1するときは後ろにやっていく
int dist[1510][1510][5];
int main() {
  rep(i,1510) rep(j,1510) rep(k,5) dist[i][j][k] = INF;
  int N; cin >> N;
  int ax, ay, bx, by; cin >> ax >> ay >> bx >> by;
  ax--, ay--, bx--, by--;
  vector<string> vec(N);
  rep(i,N) cin >> vec[i];
  deque<P> deq;  // (cost, x, y, 方向)→P(int, T(x,y,dir))
  deq.push_back(P(0, T(ax, ay, 0)));
  dist[ax][ay][0] = 0;
  while(!deq.empty()) {
    int cost = deq.front().first;
    int x, y, dirb;
    tie(x, y, dirb) = deq.front().second;
    deq.pop_front();
    if(dist[x][y][dirb] != cost) continue;
    rep(i,4) {
      int nx = x + next_i[i];
      int ny = y + next_j[i];
      int ndir = dir[i];
      if(nx < 0 || ny < 0 || nx > N-1 || ny > N-1) continue;
      if(vec[nx][ny] == '#') continue;
      int ncost = 0;
      if(ndir != dirb) ncost++;
      if(dist[nx][ny][ndir] <= dist[x][y][dirb] + ncost) continue;
      // 更新
      dist[nx][ny][ndir] = dist[x][y][dirb] + ncost;
      if(ndir == dirb) deq.push_front(P(dist[nx][ny][ndir], T(nx, ny, ndir)));
      else deq.push_back(P(dist[nx][ny][ndir], T(nx, ny, ndir)));
    }
  }
  int ans = INF;
  rep(i,5) ans = min(ans, dist[bx][by][i]);
  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}