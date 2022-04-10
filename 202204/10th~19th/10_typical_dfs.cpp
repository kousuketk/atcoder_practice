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
vector<int> next_i = {1, -1, 0, 0};
vector<int> next_j = {0, 0, 1, -1};

void rec(int i, int j, vector<string> &road, vector<vector<int>> &dist, int H, int W) {
  rep(k,4) {
    int ni = i + next_i[k];
    int nj = j + next_j[k];
    if(ni < 0 || nj < 0 || ni > H-1 || nj > W-1) continue;
    if(road[ni][nj] == '#') continue;
    if(dist[ni][nj] < INF) continue;
    dist[ni][nj] = dist[i][j] + 1;
    rec(ni, nj, road, dist, H, W);
  }
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> road(H);
  rep(i,H) cin >> road[i];
  int si, sj, gi, gj;
  rep(i,H) rep(j,W) {
    if(road[i][j] == 's') si = i, sj = j;
    if(road[i][j] == 'g') gi = i, gj = j;
  }
  vector<vector<int>> dist(H, vector<int>(W));
  rep(i,H) rep(j,W) dist[i][j] = INF;
  dist[si][sj] = 0;
  rec(si, sj, road, dist, H, W);
  if(dist[gi][gj] == INF) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}