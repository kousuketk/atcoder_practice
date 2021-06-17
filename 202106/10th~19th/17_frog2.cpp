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
  int N, K; cin >> N >> K;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  ll dp[100100];
  rep(i,100100) dp[i] = INF;
  dp[0] = 0;
  for(int i = 1; i < N; i++) {
    for(int j = 1; j <= K; j++) {
      if(i-j >= 0) dp[i] = min(dp[i], dp[i-j]+abs(vec[i-j]-vec[i]));
    }
  }
  cout << dp[N-1] << endl;
}