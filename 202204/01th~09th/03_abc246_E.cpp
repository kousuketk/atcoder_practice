#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using T = tuple<int,int,int>;
using P = pair<int, T>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> dx = {1, 1, -1, -1};
vector<int> dy = {1, -1, 1, -1};
vector<int> dirvec = {1, 2, 3, 4};

int dist[1510][1510][5];  // (x, y)の前にdir(方向)から来たときの最小コスト
vector<string> vec;
int N;

bool check(int x, int y) {
  if(x < 0 || y < 0) return false;
  if(x > N-1 || y > N-1) return false;
  if(vec[x][y] == '#') return false;
  return true;
}

int main() {
  rep(i,1510) rep(j,1510) rep(k,5) dist[i][j][k] = INF;
  cin >> N;
  vec.resize(N);
  int ax, ay, bx, by; cin >> ax >> ay >> bx >> by;
  ax--, ay--, bx--, by--;
  rep(i,N) cin >> vec[i];
  priority_queue<P, vector<P>, greater<P>> que;  // cost, T(x, y, dir)
  que.push(P(0, T(ax, ay, 0)));
  rep(k,5) dist[ax][ay][k] = 0;
  while (!que.empty()) {
    P tmp = que.top(); que.pop();
    int cost = tmp.first;
    int x, y, dir;
    tie(x, y, dir) = tmp.second;
    if(dist[x][y][dir] != cost) continue;
    rep(i,4) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      int ndir = dirvec[i];
      if(!check(nx, ny)) continue;  // チェックで引っかかったら次の方向を見る
      int tmp_cost = cost;
      if(dir != ndir) tmp_cost++;  // 方向が違かったら+1
      if(dist[nx][ny][ndir] <= tmp_cost) continue;
      dist[nx][ny][ndir] = tmp_cost;
      que.push(P(dist[nx][ny][ndir], T(nx, ny, ndir)));  // 次の探索のためpushして終わり
    }
  }
  int ans = INF;
  rep(k,5) ans = min(ans, dist[bx][by][k]);
  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}

// while文のところで計算量かかってしまっていて、TLEしている。
// →細分化できるところは細分化してwhile文とかを使わずに、ダイクストラで処理すること
// cost, x, y, dir(方向)を付け足す→前と同じ方向だったらcostをプラスせずにダイクストラを回せる
// →while文で余計な計算をせずに1回ごとにダイクストラで計算ができる
// →計算量O(N^2*log(N^2))≒10^7
// →dequeを使ってO(N^2)