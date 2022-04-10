#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<string,string>;
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
  vector<P> vec(N);
  rep(i,N) {
    string s, t; cin >> s >> t;
    vec[i] = P(s, t);
  }
  rep(i,N) {
    string s = vec[i].first;
    string t = vec[i].second;
    bool s_flag = false;
    bool t_flag = false;
    rep(j,N) {
      if(i == j) continue;
      string s2 = vec[j].first;
      string t2 = vec[j].second;
      if(s == s2 || s == t2) s_flag = true;
      if(t == s2 || t == t2) t_flag = true;
    }
    if(s_flag && t_flag) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}