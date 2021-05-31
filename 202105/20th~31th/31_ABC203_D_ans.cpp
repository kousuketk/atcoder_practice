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
  int N, K;
  cin >> N >> K;
  vector<vector<int>> a(N, vector<int>(N));
  rep(i,N)rep(j,N) cin >> a[i][j];
  int L = K*K/2+1;

  int wa = -1, ac = INF;
  while(wa+1 < ac) {
    int wj = (wa+ac)/2;
    bool ok = false;
    
    // 累積和テーブル
    vector<vector<int>> s(N+1, vector<int>(N+1));
    // 配列のコピー
    rep(i,N)rep(j,N) s[i+1][j+1] = a[i][j]>wj?1:0;
    // 横の累積和
    rep(i,N+1)rep(j,N) s[i][j+1] += s[i][j];
    // 縦の累積和
    rep(i,N)rep(j,N+1) s[i+1][j] += s[i][j];
    // 四つ角からK*K区画のwj以上の数を取る
    rep(i,N-K+1)rep(j,N-K+1) {
      int now = s[i+K][j+K];
      now -= s[i][j+K];
      now -= s[i+K][j];
      now += s[i][j];
      if(now < L) ok = true;
    }
    if(ok) ac = wj; else wa = wj;
  }
}