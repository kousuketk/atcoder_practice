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
int MAX_N = 1005;
int w, h;

vector<int> compress(vector<int> &vec1, vector<int> &vec2, int upper) {
  vector<int> next = {-1, 0, 1};
  int siz = vec1.size();
  vector<int> comp;
  rep(i,siz) {
    rep(j,3) {
      int val1 = vec1[i] + next[j];
      int val2 = vec2[i] + next[j];
      if(val1 >= 0 && val1 < upper) comp.push_back(val1);
      if(val2 >= 0 && val2 < upper) comp.push_back(val2);
    }
  }
  sort(ALL(comp));
  comp.erase(unique(ALL(comp)), comp.end());
  rep(i,siz) {
    int idx1 = lower_bound(ALL(comp), vec1[i]) - comp.begin();
    int idx2 = lower_bound(ALL(comp), vec2[i]) - comp.begin();
    vec1[i] = idx1;
    vec2[i] = idx2;
  }
  return comp;
}

int main() {
  cin >> w >> h;
  int N; cin >> N;
  vector<int> X1(N), X2(N), Y1(N), Y2(N);
  rep(i,N) cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
  vector<int> compX = compress(X1, X2, w);
  vector<int> compY = compress(Y1, Y2, h);
  int compW = compX.size();
  int compH = compY.size();
  vector<vector<bool>> fld(compW, vector<bool>(compH, false));
  // 圧縮した領域を塗る
  rep(i,N) {
    int x1 = X1[i];
    int x2 = X2[i];
    int y1 = Y1[i];
    int y2 = Y2[i];
    for(int x = x1; x <= x2; x++) for(int y = y1; y <= y2; y++) fld[x][y] = true;
  }
  rep(i,compW) {
    rep(j,compH) {
      if(fld[i][j]) cout << "#";
      else cout << ".";
    }
    cout << endl;
  }
  // fldに対して領域を求めていく
  vector<vector<bool>> seen(compW, vector<bool>(compH, false));
  vector<int> next_i = {-1, 1, 0, 0};
  vector<int> next_j = {0, 0, -1, 1};
  int ans = 0;
  rep(i,compW) {
    rep(j,compH) {
      if(seen[i][j] || fld[i][j]) continue;
      ans++;
      queue<P> que;
      cout << i << " " << j << endl;
      que.push(P(i, j));
      while(!que.empty()) {
        P tmp = que.front(); que.pop();
        int ii = tmp.first;
        int jj = tmp.second;
        seen[ii][jj] = true;
        rep(k,4) {
          int ni = ii + next_i[k];
          int nj = jj + next_j[k];
          if(ni < 0 || nj < 0 || ni > compW-1 || nj > compH-1) continue;
          if(seen[ni][nj]) continue;
          if(fld[ni][nj]) continue;
          que.push(P(ni, nj));
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

// https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_e