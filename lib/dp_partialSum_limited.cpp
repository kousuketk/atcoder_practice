#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int N, K;
int val[110], amount[110];
int dp[110][1000100];
// dp[i+1][j]: i番目までの数のグループを使って数jを作ったときに
//             i番目のamount[i]が最大何個余るか

int main() {
  cin >> N >> K;
  rep(i,N) cin >> val[i];
  rep(i,N) cin >> amount[i];

  rep(i,110)rep(j,1000100) dp[i][j] = -1;
  dp[0][0] = 0;

  // DPループ
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= K; j++) {
      if(dp[i][j] >= 0) {
        // i-1番目まででjを作れている時
        dp[i+1][j] = amount[i];
      } else if(j-amount[i]>= 0 && dp[i+1][j-amount[i]]>0) {
        // amount[i]の個数が残っており、-1することで更新できる
        dp[i+1][j] = dp[i+1][j-amount[i]]-1;
      } else {
        // それ以外のときは数jを作れない
        dp[i][j] = -1;
      }
    }
  }
  // N-1番目の部分和Kを見る
  cout << dp[N][K] << endl;
}


// dp[i][j]としたが、i番目であるかどうかは持たなくていいので
// dp[j]とすることで、メモリを節約することができる
// ↓
// ↓
// ---------------------------- 以下 ---------------------------------


int N, K;
int val[110], amount[110];
int dp[1000100];
// dp[i+1][j]: i番目までの数のグループを使って数jを作ったときに
//             i番目のamount[i]が最大何個余るか

int main() {
  cin >> N >> K;
  rep(i,N) cin >> val[i];
  rep(i,N) cin >> amount[i];

  rep(j,1000100) [j] = -1;
  dp[0] = 0;

  // DPループ
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= K; j++) {
      if(dp[j] >= 0) {
        // i-1番目まででjを作れている時
        dp[j] = amount[i];
      } else if(j-amount[i]>= 0 && dp[j-amount[i]]>0) {
        // amount[i]の個数が残っており、-1することで更新できる
        dp[j] = dp[j-amount[i]]-1;
      } else {
        // それ以外のときは数jを作れない
        dp[j] = -1;
      }
    }
  }
  // N-1番目の部分和Kを見る
  cout << dp[K] << endl;
}