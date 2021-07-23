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

int main() {
  int H, W; cin >> H >> W;
  vector<vector<int>> vec(H, vector<int>(W));
  int min_val = INF;
  rep(i,H) rep(j, W) {
    int tmp; cin >> tmp;
    vec[i][j] = tmp;
    min_val = min(min_val, tmp);
  }
  int ans = 0;
  rep(i,H) rep(j, W) {
    ans += vec[i][j] - min_val;
  }
  cout << ans << endl;
}