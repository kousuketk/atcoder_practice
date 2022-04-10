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
int H = 10;
int W = 10;
vector<string> vec(H);
void rec(int i, int j, vector<vector<bool>> &seen) {
  seen[i][j] = true;
  rep(k,4) {
    int ni = i + next_i[k];
    int nj = j + next_j[k];
    if(ni < 0 || nj < 0 || ni > H-1 || nj > W-1) continue;
    if(vec[ni][nj] == 'x') continue;
    if(seen[ni][nj]) continue;
    rec(ni, nj, seen);
  }
  return;
}

// 判定O(100), 島を陸にする全通りO(100)
int main() {
  bool ans = false;
  rep(i,H) cin >> vec[i];
  // 島を陸にすることを全探索する
  rep(i,H) {
    rep(j,W) {
      char c = vec[i][j];
      vec[i][j] = 'o';
      // 判定する
      int cnt = 0;
      vector<vector<bool>> seen(H, vector<bool>(W));
      rep(ii,H) {
        rep(jj,W) {
          if(vec[ii][jj] == 'x' || seen[ii][jj]) continue;
          rec(ii, jj, seen);
          cnt++;
        }
      }
      vec[i][j] = c;
      if(cnt == 1) ans = true;
      if(ans) break;
    }
    if(ans) break;
  }
  if(ans) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}