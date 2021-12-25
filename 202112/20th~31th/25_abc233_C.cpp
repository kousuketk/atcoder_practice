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

int N;
ll X;
vector<vector<ll>> vec;
vector<ll> vec_l;

ll dfs(ll val, int depth, int idx) {
  ll new_val = val * (ll)vec[depth][idx];
  int l = vec_l[depth];
  ll res = 0;
  if(depth == N-1 && new_val == X) res++;
  if(depth == N-1 && idx == l-1) return res;
  if(depth == N-1) {
    res += dfs(val, depth, idx+1);
  } else if(idx == l-1) {
    if(new_val <= X) res += dfs(new_val, depth+1, 0);
  } else {
    if(new_val <= X) res += dfs(new_val, depth+1, 0);
    res += dfs(val, depth, idx+1);
  }
  return res;
}

int main() {
  cin >> N;
  cin >> X;
  vec.resize(N);
  vec_l.resize(N);
  rep(i,N) {
    int L; cin >> L;
    vec_l[i] = L;
    vec[i].resize(L);
    rep(j,L) cin >> vec[i][j];
  }
  ll ans = dfs(1, 0, 0);
  cout << ans << endl;
}