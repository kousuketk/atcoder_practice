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

bool dp[105][10005];
int main() {
  int N, M; cin >> N >> M;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  dp[0][0] = true;
  rep(i,N) {
    rep(j,10001) {
      int a = vec[i];
      dp[i+1][j] |= dp[i][j];
      if(j-a >= 0) dp[i+1][j] |= dp[i][j-a];
    }
  }
  if(dp[N][M]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}