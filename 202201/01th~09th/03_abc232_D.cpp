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

vector<string> mass;
int memo[105][105];
int H, W;

int dfs(int i, int j, int deep) {
  int res = deep;
  // i+1に移動できる時
  if(i < H-1 && mass[i+1][j] == '.') {
    res = max(dfs(i+1, j, deep+1), res);
  }
  if(j < W-1 && mass[i][j+1] == '.') {
    res = max(dfs(i, j+1, deep+1), res);
  }
  return res;
}

int main() {
  memset(memo, -1, sizeof(memo));
  cin >> H >> W;
  mass.resize(H);
  rep(i,H) {
    string s; cin >> s;
    mass[i] = s;
  }
  int ans = dfs(0, 0, 1);
  cout << ans << endl;
}