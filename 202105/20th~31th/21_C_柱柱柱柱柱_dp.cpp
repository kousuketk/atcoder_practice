#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;

vector<int> memo;
vector<bool> visited;
vector<int> vec;

int f(int v) {
  if(v == 0) return memo[0] = 0;
  if(v == 1) return memo[1] = abs(vec[0]-vec[1]);
  if(visited[v]) return memo[v];
  visited[v] = true;
  int res = min(f(v-1)+abs(vec[v-1]-vec[v]), f(v-2)+abs(vec[v-2]-vec[v]));
  return memo[v] = res;
}

int main() {
  int N;
  cin >> N;
  memo.resize(N, INF);
  visited.resize(N, false);
  vec.resize(N);
  rep(i,N) cin >> vec[i];
  cout << f(N-1) << endl;
}