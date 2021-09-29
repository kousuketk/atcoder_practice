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
const ll MOD = 998244353;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

ll dp[100100][10];

int main() {
  int N; cin >> N;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  int a = (vec[0]+vec[1])%10;
  int b = (vec[0]*vec[1])%10;
  dp[1][a]++;
  dp[1][b]++;
  for(int i = 2; i < N; i++) {
    for(int j = 0; j < 10; j++) {
      int tmp = dp[i-1][j];
      int a = (vec[i]+j)%10;
      int b = (vec[i]*j)%10;
      dp[i][a] = (dp[i][a]+tmp) % MOD;
      dp[i][b] = (dp[i][b]+tmp) % MOD;
    }
  }
  rep(i,10) cout << dp[N-1][i] << endl;
}