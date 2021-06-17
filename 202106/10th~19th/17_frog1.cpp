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
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  ll dp[100100];
  dp[0] = 0;
  dp[1] = abs(vec[0] - vec[1]);
  for(int i = 2; i < N; i++) {
    dp[i] = min(dp[i-2]+abs(vec[i-2]-vec[i]), dp[i-1]+abs(vec[i-1]-vec[i]));
  }
  cout << dp[N-1] << endl;
}