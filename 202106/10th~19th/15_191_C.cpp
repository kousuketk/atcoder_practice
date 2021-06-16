#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
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
  int H, W;
  cin >> H >> W;
  vector<string> vec(H);
  rep(i,H) cin >> vec[i];
  ll ans = 0;
  for(int i = 0; i < H-1; i++) {
    for(int j = 0; j < W-1; j++) {
      // vec[i][j], vec[i+1][j], vec[i][j+1], vec[i+1][j]を見ていく
      int tmp_count = 0;
      if(vec[i][j] == '#') tmp_count++;
      if(vec[i+1][j] == '#') tmp_count++;
      if(vec[i][j+1] == '#') tmp_count++;
      if(vec[i+1][j+1] == '#') tmp_count++;
      if(tmp_count % 2 == 1) ans++;
    }
  }
  cout << ans << endl;
}