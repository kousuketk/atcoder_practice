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

// a:0, b:1, c:2, ..., z:25
Graph G;  // 文字の依存関係
vector<int> nug;  // 入次数
int siz = 26;
bool check(string A, string B) {
  bool res = true;
  bool flag = false;
  int n = min((int)A.size(), (int)B.size());
  rep(i,n) {
    if(A[i] != B[i]) {
      G[(int)(A[i]-'a')].push_back((int)(B[i]-'a'));
      nug[B[i]-'a']++;
      flag = true;
      break;
    }
  }
  if(!flag && A > B) return false;
  else return true;
}

int main() {
  int N; cin >> N;
  G.resize(siz);
  nug.resize(siz);
  rep(i,N) {
    string a, b; cin >> a >> b;
    if(!check(a,b)) {
      cout << -1 << endl;
      return 0;
    }
  }
  // 0(a)から見ていって、入次数が0のものから先頭に入れていく
  string ans = "";
  vector<int> used(siz, false);
  bool flag = true;
  rep(j,siz) {
    rep(i,siz) {
      if(nug[i] == 0 && !used[i]) {
        ans += char(i + 'a');
        for(int nv : G[i]) nug[nv]--;
        used[i] = true;
        break;
      }
      if(i == siz-1) flag = false;
    }
  }
  if(flag) cout << ans << endl;
  else cout << -1 << endl;
  return 0;
}

// https://atcoder.jp/contests/tenka1-2016-quala/tasks/tenka1_2016_qualA_c