#include "bits/stdc++.h" 
using namespace std; 
using ll = long long;

int h, w;
bool used[16][16];

ll dfs(int i, int j, int a, int b) {
  if(a < 0 || b < 0) return 0;
  if(j == w) j = 0, i++;
  if(i == h) return 1;
  if(used[i][j]) return dfs(i, j+1, a, b);
  ll res = 0;
  used[i][j] = true;
  res += dfs(i, j+1, a, b-1);
  if(j+1 < w && !used[i][j+1]) {
    used[i][j+1] = true;
    res += dfs(i, j+1, a-1, b);
    used[i][j+1] = false;
  }
  if(i+1 < h && !used[i+1][j]) {
    used[i+1][j] = true;
    res += dfs(i, j+1, a-1, b);
    used[i+1][j] = false;
  }
  used[i][j] = false;
  return res;
}

int main() {
  cin >> h >> w;
  int a, b;
  cin >> a >> b;
  cout << dfs(0,0,a,b) << endl;;
  return 0;
}