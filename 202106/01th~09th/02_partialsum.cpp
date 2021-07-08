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
  int N, A;
  cin >> N;
  vector<int> a(N);
  rep(i,N) cin >> a[i];
  cin >> A;
  bool dp[110][10100];
  dp[0][0] = true;
  for(int i = 1; i <= N; i++) {
    for(int b = 0; b <= A; b++) {
      if(dp[i-1][b]) {
        dp[i][b] = true;
        continue;
      }
      if(b >= a[i-1] && dp[i-1][b-a[i-1]]){
        dp[i][b] = true;
      } else {
        dp[i][b] = false;
      }
    }
  }
  if(dp[N][A]) cout << "YES" << endl;
  else cout << "NO" << endl;
}