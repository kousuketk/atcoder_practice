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
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int main() {
  int H, W; cin >> H >> W;
  vector<vector<int>> vec(H, vector<int>(W));
  rep(i,H) {
    rep(j,W) {
      int a; cin >> a;
      vec[i][j] = a;
    }
  }
  rep(j,W) {
    rep(i,H) {
      cout << vec[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}