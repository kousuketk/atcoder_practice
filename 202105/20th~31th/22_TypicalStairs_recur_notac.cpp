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
bool flag = false;

int f(int v) {
  if(v == 0) return 1;
  if(v == 1) {
    if(vec[0] == 1) return -1;
    else return 1;
  }
  if(visited[v]) return memo[v];
  visited[v] = true;
  auto result = find(vec.begin(), vec.end(), v);
  if(result != vec.end()) {
    return memo[v] = -1;
  }
  int res;
  if(memo[v-1] == -1 && memo[v-2] == -1) {
    flag = true;
    res = -1;
  } else if(memo[v-1] == -1) {
    res = memo[v-2];
  } else if(memo[v-2] == -1) {
    res = memo[v-1];
  } else {
    res = (memo[v-1] + memo[v-2]) % 1000000007;
  }
  return memo[v] = res;
}

int main() {
  int N, M;
  cin >> N >> M;
  memo.resize(N);
  visited.resize(N, false);
  vec.resize(M);
  for(int i = 0; i < M; i++) cin >> vec[i];
  int res = f(N);
  if(flag) cout << 0 << endl;
  else cout << res << endl;
  return 0;
}