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

vector<string> road;
int N;

// vがスタート(今見ている頂点), cntが全部のカウント(スタートから何個目か), missが何個ミスっているか(白があったか2個までならセーフ)
// dir(1:右, 2:下, 3:右下, 4:左下 0:最初)
bool dfs(int i, int j, int dir, int cnt, int miss) {
  if(dir == 0) {
    // 右にいく(少なくとも右に4つ残っている必要がある)
    if(N-j >= 4) {
      if(dfs(i, j+1, 1, 1, 0)) return true;
    }
    // 下にいく
    if(N-i >= 4) {
      if(dfs(i+1, j, 2, 1, 0)) return true;
    }
    // 右下にいく
    if(N-j >= 4 && N-i >= 4) {
      // そこの斜めで6個を形成できるか？
      int upper = min(i,j);
      int downer = min(N-1-i, N-1-j);
      if(upper + downer >= 6) {
        if(dfs(i+1, j+1, 3, 1, 0)) return true;
      }
    }
    // 左下にいく
    if(j >= 3 && N-i >= 4) {
      // そこの斜めで6個を形成できるか？
      int upper = min(i, N-1-j);
      int downer = min(N-1-i, j);
      if(upper + downer >= 6) {
        if(dfs(i+1, j-1, 4, 1, 0)) return true;
      }
    }
  } else {
    cnt++;
    if(road[i][j] == '.') miss++;
    if(cnt - miss >= 4) return true;
    if(miss > 2) return false;
    if(dir == 1) {
      // もし次がなかったらfalse
      if(j >= N-1) return false;
      if(dfs(i, j+1, dir, cnt, miss)) return true;
    }
    if(dir == 2) {
      if(i >= N-1) return false;
      if(dfs(i+1, j, dir, cnt, miss)) return true;
    }
    if(dir == 3) {
      if(i >= N-1 || j >= N-1) return false;
      if(dfs(i+1, j+1, dir, cnt, miss)) return true;
    }
    if(dir == 4) {
      if(i >= N-1 || j <= 0) return false;
      if(dfs(i+1, j-1, dir, cnt, miss)) return true;
    }
  }
  return false;
}

int main() {
  cin >> N;
  road.resize(N);
  rep(i,N) cin >> road[i];
  bool ans = false;
  rep(i,N) {
    rep(j,N) {
      if(road[i][j] == '#') {
        bool flag = dfs(i, j, 0, 0, 0);
        if(flag) {
          ans = true;
          break;
        }
      }
    }
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}