#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
// const ll INF = 1100100100100100100;
const int INF = 1001001001;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

vector<int> vec;
int dp[510][510];

int dfs(int l, int r) {
  if(dp[l][r] != -1) return dp[l][r];
  if(l == r) {
    cout << l << " " << r << endl;
    return 1;
  }
  
  int res = INF;
  for(int i = l; i < r; i++) {
    if(vec[i] == vec[i+1]) {
      // このときに、vec[i]=vec[i]+1 にしてvec[i+1]をなくしたい
      vec[i] = vec[i] + 1;
      if(i+1 == r) res = min(res, dfs(l, i));
      else res = min(res, dfs(l, i) + dfs(i+2, r));
      // res = min(res, dfs(l, i) + dfs(i+1, r) - 1);
      vec[i] = vec[i] - 1;
    } else {
      res = min(res, dfs(l, i) + dfs(i+1, r));
    }
  }

  return dp[l][r] = res;
}

int main()
{
  int N; cin >> N;
  vec.resize(N);
  rep(i,N) cin >> vec[i];
  rep(i,510) rep(j,510) dp[i][j] = -1;
  cout << dfs(0, N-1) << endl;
}
