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
vector<int> next_i = {1, 1, 1, -1, -1, -1, 0, 0};
vector<int> next_j = {0, 1, -1, 0, 1, -1, 1, -1};

int H, W;
void rec(int i, int j, vector<vector<int>> &vec, vector<vector<bool>> &seen) {
  seen[i][j] = true;
  rep(k,8) {
    int ni = i + next_i[k];
    int nj = j + next_j[k];
    if(ni < 0 || nj < 0 || ni > H-1 || nj > W-1) continue;
    if(vec[ni][nj] == 0) continue;
    if(seen[ni][nj]) continue;
    rec(ni, nj, vec, seen);
  }
}

int main() {
  vector<int> ans_vec;
  while(true) {
    cin >> W >> H;
    if(W == 0 && H == 0) break;
    vector<vector<int>> vec(H, vector<int>(W));
    vector<vector<bool>> seen(H, vector<bool>(W));
    rep(i,H) rep(j,W) cin >> vec[i][j];
    int ans = 0;
    rep(i,H) rep(j,W) {
      if(seen[i][j] || vec[i][j] == 0) continue;
      rec(i, j, vec, seen);
      ans++;
    }
    ans_vec.push_back(ans);
  }
  rep(i,(int)ans_vec.size()) cout << ans_vec[i] << endl;
  return 0;
}