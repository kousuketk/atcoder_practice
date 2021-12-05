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
  vector<string> G(H);
  rep(i,H) cin >> G[i];
  rep(i,H) {
    rep(j,W) {
      if(G[i][j] == '.') {
        vector<int> tmp_vec = {0,0,0,0,0};
        if(i > 0 && G[i-1][j] != '.') tmp_vec[G[i-1][j] - '0' - 1]++;
        if(i < H-1 && G[i+1][j] != '.') tmp_vec[G[i+1][j] - '0' - 1]++;
        if(j > 0 && G[i][j-1] != '.') tmp_vec[G[i][j-1] - '0' - 1]++;
        if(j < W-1 && G[i][j+1] != '.') tmp_vec[G[i][j+1] - '0' - 1]++;
        int nv = 0;
        for(int tmp = 0; tmp < 5; tmp++) {
          if(tmp_vec[tmp] < 1) {
            nv = tmp+1;
            break;
          }
        }
        G[i][j] = '0' + nv;
      }
    }
  }
  rep(i,H) cout << G[i] << endl;
}