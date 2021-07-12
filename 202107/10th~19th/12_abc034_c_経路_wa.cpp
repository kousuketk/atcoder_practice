#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
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

int W, H;
ll memo[10010][10010];
bool seen[10010][10010];

ll rec(int i, int j) {
  if(i == H-1 && j == W-2) return 1;
  if(i == H-2 && j == W-1) return 1;
  if(seen[i][j]) return memo[i][j];
  seen[i][j] = true;
  ll res = 0;
  
  // 右へ移動
  if(j < W-1) res = (res + rec(i, j+1)) % MOD;
  // 下へ移動
  if(i < H-1) res = (res + rec(i+1, j)) % MOD;
  
  return memo[i][j] = res;
}

int main() {
  cin >> W >> H;
  cout << rec(0,0) << endl;
  return 0;
}

// O(W*H)だから回らないんだと思う→nCrで求める