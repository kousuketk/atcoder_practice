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

map<ll, ll> mp;
ll dfs(ll num) {
  if(num < 4) return num;
  if(mp.count(num)) return mp[num];
  ll res = 1;
  res = (res * dfs(num/2)) % MOD;
  if(num % 2 == 0) res = (res * dfs(num/2)) % MOD;
  else res = (res * dfs(num/2 + 1)) % MOD;
  
  return mp[num] = res;
}

int main() {
  ll X; cin >> X;
  ll ans = dfs(X);
  cout << ans << endl;
}