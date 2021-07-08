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
  int N; cin >> N;
  vector<T> vec(N);
  rep(i,N) {
    int a, b, c;
    cin >> a >> b >> c;
    vec[i] = T(a, b, c);
  }
  ll dp[100100][3];
  dp[0][0] = get<0>(vec[0]);
  dp[0][1] = get<1>(vec[0]);
  dp[0][2] = get<2>(vec[0]);
  for(int i = 1; i < N; i++) {
    dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + get<0>(vec[i]);
    dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + get<1>(vec[i]);
    dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + get<2>(vec[i]);
  }
  int ans = max({dp[N-1][0], dp[N-1][1], dp[N-1][2]});
  cout << ans << endl;
}