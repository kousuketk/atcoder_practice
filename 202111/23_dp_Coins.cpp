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

double dp[3010][3010];
int main() {
  int N; cin >> N;
  rep(i,N) {
    double p; cin >> p;
    if(i == 0) {
      dp[i][1] = p;
      dp[i][0] = 1-p;
      continue;
    }
    for(int j = 0; j <= i+1; j++) {
      if(j == 0) {
        dp[i][j] = dp[i-1][j]*(1-p);
      } else if(j == i+1) {
        dp[i][j] = dp[i-1][j-1]*p;
      } else {
        dp[i][j] += dp[i-1][j-1]*p;
        dp[i][j] += dp[i-1][j]*(1-p);
      }
    }
  }
  double ans = 0;
  for(int j = N; j >= (N+1)/2; j--) {
    ans += dp[N-1][j];
  }
  cout << fixed << setprecision(10) << ans << endl;
}