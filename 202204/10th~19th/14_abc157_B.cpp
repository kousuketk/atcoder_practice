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

int main() {
  int h = 3, w = 3;
  int A[3][3];
  bool C[3][3];
  rep(i,h) rep(j,w) cin >> A[i][j];
  rep(i,h) rep(j,w) C[i][j] = false;
  int N; cin >> N;
  rep(n,N) {
    int b; cin >> b;
    rep(i,h) rep(j,w) {
      if(A[i][j] == b) C[i][j] = true;
    }
  }
  bool flag = false;
  // 縦で見る
  rep(j,w) {
    int cnt = 0;
    rep(i,h) {
      if(C[i][j]) cnt++;
    }
    if(cnt == h) flag = true;
  }
  // 横で見る
  rep(i,h) {
    int cnt = 0;
    rep(j,w) {
      if(C[i][j]) cnt++;
    }
    if(cnt == w) flag = true;
  }
  // ななめ目で見る
  if(C[0][0] && C[1][1] && C[2][2] || C[0][2] && C[1][1] && C[2][0]) flag = true;
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}