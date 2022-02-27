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

vector<int> A;
vector<int> B;
// 何個マッチするか？
int check_cnt(int one, int two, int three, int i) {
  if(one != B[i]) return 0;
  if(two != B[i+1]) return 1;
  if(three != B[i+2]) return 2;
  return 3;
}
// マッチするならよりマッチする方向に変換する
void check_act(int ori, int one, int two, int i) {
  int max_val = max({ori, one, two});
  if(max_val == ori) return;
  if(max_val == one) {
    int tmpy = A[i+1];
    int tmpz = A[i+2];
    A[i+1] = A[i];
    A[i+2] = tmpy;
    A[i] = tmpz;
  } else if(max_val == two) {
    int tmpy = A[i+1];
    int tmpz = A[i+2];
    A[i+2] = A[i];
    A[i] = tmpy;
    A[i+1] = tmpz;
  }
  return;
}

// 前から見ていって、3パータンのうち、最初がマッチしなかったら一致できない. マッチするならよりマッチする方向に変換する
int main() {
  int N; cin >> N;
  A.resize(N);
  B.resize(N);
  rep(i,N) cin >> A[i];
  rep(i,N) cin >> B[i];
  bool ans = true;
  rep(i,N-2) {
    int x = A[i];
    int y = A[i+1];
    int z = A[i+2];
    int ori = check_cnt(x, y, z, i);
    int one = check_cnt(z, x, y, i);
    int two = check_cnt(y, z, x, i);
    if(ori == 0 && one == 0 && two == 0) {
      ans = false;
      break;
    }
    check_act(ori, one, two, i);
    if(i == N-3) {
      int max_val = max({ori, one, two});
      if(max_val != 3) ans = false;
    }
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}