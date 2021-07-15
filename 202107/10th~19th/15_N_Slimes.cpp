#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

vector<ll> vec;
ll dp[410][410];
vector<ll> S;

ll dfs(int l, int r) {
  if(dp[l][r] != -1) return dp[l][r];
  if(l >= r) return 0;

  ll res = INF;
  for(int i = l; i < r; i++) {
    res = min(res, dfs(l, i) + dfs(i+1, r) + S[r+1] - S[l]); // l~i, i+1~rの和 = l~rの和
  }
  
  return dp[l][r] = res;
}

int main()
{
  int N; cin >> N;
  vec.resize(N);
  S.resize(N+1);
  rep(i,N) cin >> vec[i];
  rep(i,N) S[i+1] = S[i] + vec[i];
  rep(i,410) rep(j,410) dp[i][j] = -1;
  cout << dfs(0, N-1) << endl;
}

// 32bit整数型に収まらない時、INFをllにするの忘れがち(INFをぎりぎりまで最大にする)