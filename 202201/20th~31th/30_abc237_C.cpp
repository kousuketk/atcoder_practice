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
  // before_a：前に何個のa
  // before_a：後に何個のa
  // を数えて、足りない文を前に追加して回分になるかチェック
  string s; cin >> s;
  int before_a = 0;
  int aftere_a = 0;
  int n = s.size();
  rep(i,n) {
    if(s[i] != 'a') break;
    before_a++;
  }
  rep(i,n) {
    if(s[n-i-1] != 'a') break;
    aftere_a++;
  }
  int diff = aftere_a - before_a;
  if(diff < 0) {
    cout << "No" << endl;
    return 0;
  }
  s = string(diff, 'a') + s;
  // sの前後から見ていく
  bool flag = true;
  int idx1 = 0;
  int idx2 = n+diff-1;
  while(idx1 < idx2) {
    if(s[idx1] != s[idx2]) {
      flag = false;
      break;
    }
    idx1++;
    idx2--;
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}