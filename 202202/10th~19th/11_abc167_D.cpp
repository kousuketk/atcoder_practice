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

int cntLoop(vector<int>& vec, int start_loop) {
  int now = start_loop;
  int cnt = 1;
  while (true) {
    now = vec[now];
    if(now == start_loop) return cnt;
    cnt++;
  }
}

int cntBefore(vector<int>& vec, int start_loop) {
  int now = 0;
  int cnt = 0;
  while(true) {
    now = vec[now];
    if(now == start_loop) return cnt;
    cnt++;
  }
}

int main() {
  int N; cin >> N;
  ll K; cin >> K;
  vector<int> vec(N);
  rep(i,N) {
    int a; cin >> a;
    a--;
    vec[i] = a;
  }
  vector<int> visited(N, false);
  visited[0] = true;
  int now = 0;
  int start_loop = 0;
  rep(i,N) {
    now = vec[now];
    if(visited[now]) {
      start_loop = now;
      break;
    }
    visited[now] = true;
  }
  // ループ開始が分かれば、ループ前のカウントとループ内のカウントを取れる
  int cnt_loop = cntLoop(vec, start_loop);
  int cnt_before = cntBefore(vec, start_loop);
  int ans = 0;
  if(K <= cnt_before) {  // ループに行く前だったら普通に調べる
    rep(i,K) ans = vec[ans];
  } else {
    K -= (cnt_before+1);
    K = K % cnt_loop;
    // ループのK番目である
    ans = start_loop;
    rep(i,K) ans = vec[ans];
  }
  cout << ans << endl;
}