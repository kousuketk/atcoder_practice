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
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int H, W; cin >> H >> W;
  vector<string> g(H);
  rep(i,H) cin >> g[i];
  bool flag = true;
  rep(i,H)rep(j,W) {
    // g[i][j]について判定
    if(g[i][j] == '.') continue;
    // 上にあるか
    if(i != 0 && g[i-1][j] == '#') continue;
    // 下にあるか
    if(i != H-1 && g[i+1][j] == '#') continue;
    // 左
    if(j != 0 && g[i][j-1] == '#') continue;
    // 右
    if(j != W-1 && g[i][j+1] == '#') continue;
    flag = false;
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}