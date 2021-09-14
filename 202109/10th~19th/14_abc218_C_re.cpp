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

int main() {
  int N; cin >> N;
  vector<string> s(N);
  rep(i,N) cin >> s[i];
  vector<string> t(N);
  rep(i,N) cin >> t[i];
  rep(k,4) {
    vector<string> tmp_s(N);
    rep(i,N) {
      rep(j,N) { // sを90度回転
        tmp_s[N-1-j][i] = s[i][j];
      }
    }
    rep(i,N) rep(j,N) s[i][j] = tmp_s[i][j];
    // tmp_sを平行移動する
    int si, sj, ti, tj;
    bool flag_s = false;
    bool flag_t = false;
    set<P> set_s;
    set<P> set_t;
    rep(i,N) {
      rep(j,N) {
        if(!flag_s && tmp_s[i][j] == '#') {
          si = i, sj = j;
          flag_s = true;
        }
        if(!flag_t && t[i][j] == '#') {
          ti = i, tj = j;
          flag_t = true;
        }
        if(flag_s && tmp_s[i][j] == '#') {
          set_s.insert(P(i-si, j-sj));
        }
        if(flag_t && t[i][j] == '#') {
          set_t.insert(P(i-ti, j-tj));
        }
      }
    }
    if(set_s == set_t) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}