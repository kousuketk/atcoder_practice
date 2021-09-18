#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<string,int>;
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
  string X; cin >> X;
  int N; cin >> N;
  vector<string> vec(N);
  rep(i,N) cin >> vec[i];
  vector<P> vec_p(N);  // P(数字, 番号)→vec_pをsortして、vec[番号]を出力
  rep(i,N) {
    string s = vec[i];
    int size = s.size();
    string after_s;
    rep(j,size) {
      char c = s[j];
      int idx = X.find_first_of(c);
      char tmp_char = idx + 97;
      after_s += tmp_char;
    }
    vec_p[i] = P(after_s, i);
    // cout << after_s << endl;
  }
  sort(ALL(vec_p));
  rep(i,N) {
    int idx = vec_p[i].second;
    cout << vec[idx] << endl;
  }
  return 0;
}