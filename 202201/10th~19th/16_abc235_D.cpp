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
const int max_val = 10000000;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

int a, N;
int size_N;
int max_cnt = 1000;
int memo[10000010];
void dfs(int num, int cnt) {
  if(num == N) max_cnt = min(max_cnt, cnt);
  if(cnt > max_cnt) return;
  if(num >= max_val || num < 0) return;  // num < 0をチェックしたらacした...(オーバーフロー)
  if(memo[num] <= cnt) return;
  // 桁チェック
  string tmp = to_string(num);
  int keta = tmp.size();
  if(keta > size_N) return;
  // メモ
  memo[num] = cnt;
  // a倍にする
  if(num*a < max_val) dfs(num*a, cnt+1);
  // 末尾を先頭にする
  if(keta > 1 && (num%10) != 0) {
    int tail = num % 10;
    int new_num = num/10 + tail*pow(10, keta-1);
    if(new_num < max_val) dfs(new_num, cnt+1);
  }
  return;
}

int main() {
  cin >> a >> N;
  string tmp = to_string(N);
  size_N = tmp.size();
  rep(i,10000010) memo[i] = INF;
  dfs(1, 0);
  int ans = memo[N];
  if(ans != INF) cout << ans << endl;
  else cout << -1 << endl;
}