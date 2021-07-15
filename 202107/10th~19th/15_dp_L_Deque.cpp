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
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

vector<int> vec;
ll dp[3010][3010];

ll dfs(int l, int r, int turn) {
  if(dp[l][r] != -1) return dp[l][r];
  if(l > r) {
    // cout << l << " " << r << endl;
    return 0;
  }
  // l==rにしたければ、以下のようにすればできそう
  // if(l == r) {
  //   if(turn == 1) return dp[l][r] = vec[l];
  //   else return dp[l][r] = -vec[l];
  // }

  ll res = 0;
  if(turn == 1) {
    res = max(dfs(l+1, r, -1) + vec[l], dfs(l, r-1, -1) + vec[r]);
  } else {
    res = min(dfs(l+1, r, 1) - vec[l], dfs(l, r-1, 1) - vec[r]);
  }

  return dp[l][r] = res;
}


int main()
{
  int N; cin >> N;
  vec.resize(N);
  rep(i,N) cin >> vec[i];
  rep(i,3010) rep(j,3010) dp[i][j] = -1;
  cout << dfs(0, N-1, 1) << endl;
}
