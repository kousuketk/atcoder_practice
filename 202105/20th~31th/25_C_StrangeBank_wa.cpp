#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;

vector<int> memo(100001, INF);
vector<bool> visited(100001, false);

int f(int v) {
  if(v == 0) return memo[0] = 0;
  if(v == 1) return memo[1] = 1;
  if(v == 6 || v == 36 || v == 216 || v == 1296 || v == 7776 || v == 46656) {
    return memo[v] = 1;
  }
  if(v == 9 || v == 81 || v == 729 || v == 6561 || v == 59049) {
    return memo[v] = 1;
  }
  if(visited[v]) return memo[v];
  visited[v] = true;
  int res = 0;
  if(v > 59049) return memo[v] = f(v-59049) + 1;
  if(v > 46656) return memo[v] = f(v-46656) + 1;
  if(v > 7776) return memo[v] = f(v-7776) + 1;
  if(v > 6561) return memo[v] = f(v-6561) + 1;
  if(v > 1296) return memo[v] = f(v-1296) + 1;
  if(v > 729) return memo[v] = f(v-729) + 1;
  if(v > 216) return memo[v] = f(v-216) + 1;
  if(v > 81) return memo[v] = f(v-81) + 1;
  if(v > 36) return memo[v] = f(v-36) + 1;
  if(v > 9) return memo[v] = f(v-9) + 1;
  if(v > 6) return memo[v] = f(v-6) + 1;
  if(v > 1) return memo[v] = f(v-1) + 1;
  return memo[v] = res;
}

int main() {
  int N;
  cin >> N;
  cout << f(N) << endl;
}