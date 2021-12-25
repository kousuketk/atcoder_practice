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

// O(N^2)の記法
int main() {
  int N; cin >> N;
  vector<int> dp(N);

  int res = 0;
  for(int i = 0; i < N; i++) {
    dp[i] = 1;
    for(int j = 0; j < i; j++) {
      if(a[j] < a[i]) {
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
    res = max(res, dp[i]);
  }
  cout << res << endl;
}

// dp[i]：i番目を最後の数とするような最長増加部分列の長さ(i番目は必ず選ばれる)
// O(N^2)の記法だと、
// 最長増加部分列(LIS)だけでなく
// 最長非減少部分列(L-NonDecreasing-S)や最長非増加部分列
// 最長減少部分列(LDS)にも対応できる
// 減少に関しては符号を逆転して持てばできそう