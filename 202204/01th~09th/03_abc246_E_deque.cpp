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
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_x = {1, 1, -1, -1};
vector<int> next_y = {1, -1, 1, -1};
vector<int> vec_dir = {1, 2, 3, 4};

int dist[1510][1510][5];
int main() {
  rep(i,1510)rep(j,1510)rep(k,5) dist[i][j][k] = INF;
  int N; cin >> N;
  int ax, ay, bx, by; cin >> ax >> ay >> bx >> by;
  ax--, ay--, bx--, by--;
  vector<string> vec(N);
  rep(i,N) cin >> vec[i];
  deque<P> deq;
  deq.push_back(P(0, T(ax, ay, 0)));
  rep(i,5) dist[ax][ay][i] = 0;
  while(!deq.empty()) {
    P pa = deq.front(); deq.pop_front();
    int cost = pa.first;
    int x, y, dir;
    tie(x, y, dir) = pa.second;
    if(dist[x][y][dir] != cost) continue;
    rep(i,4) {
      int nx = x + next_x[i];
      int ny = y + next_y[i];
      int ndir = vec_dir[i];
      if(nx < 0 || ny < 0) continue;
      if(nx > N-1 || ny > N-1) continue;
      if(vec[nx][ny] == '#') continue;
      if(dir == ndir) {
        if(dist[nx][ny][ndir] <= cost) continue;
        dist[nx][ny][ndir] = cost;
        deq.push_front(P(dist[nx][ny][ndir], T(nx, ny, ndir)));
      } else {
        if(dist[nx][ny][ndir] <= cost+1) continue;
        dist[nx][ny][ndir] = cost+1;
        deq.push_back(P(dist[nx][ny][ndir], T(nx, ny, ndir)));
      }
    }
  }
  int ans = INF;
  rep(i,5) ans = min(ans, dist[bx][by][i]);
  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}