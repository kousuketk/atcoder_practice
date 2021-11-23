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

int dp[100100];
int main() {
  int N, K; cin >> N >> K;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  rep(i,N) dp[i] = INF;
  dp[0] = 0;
  rep(i,N) {
    rep(j,K) {
      if(i+j+1 < N) dp[i+j+1] = min(dp[i+j+1], dp[i] + abs(vec[i]-vec[i+j+1]));
    }
  }
  cout << dp[N-1] << endl;
}