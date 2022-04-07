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

int vec[1010][1010];
int main() {
  int N; cin >> N;
  rep(i,N) {
    int lx, ly, rx, ry; cin >> lx >> ly >> rx >> ry;
    vec[lx][ly]++;  // 始まりを+1
    vec[rx][ly]--;  // 始まりの行の末尾を-1
    vec[lx][ry]--;  // 始まりの列の末尾を-1
    vec[rx][ry]++;  // 紙の角を+1
  }
  // 横で見る
  rep(i,1001) {
    rep(j,1001) {
      vec[i][j+1] += vec[i][j];
    }
  }
  // 縦で見る
  rep(i,1001) {
    rep(j,1001) {
      vec[i+1][j] += vec[i][j];
    }
  }
  map<int, int> mp;
  rep(i,1001) {
    rep(j,1001) {
      int val = vec[i][j];
      mp[val]++;
    }
  }
  // 1~N枚までを出力
  rep(i,N) {
    if(mp.count(i+1)) cout << mp[i+1] << endl;
    else cout << 0 << endl;
  }
  return 0;
}