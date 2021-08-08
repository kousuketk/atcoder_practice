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

int main() {
  int N; cin >> N;
  string s; cin >> s;
  int itr_front = 0;  // 前から見ていく
  int itr_back = N-1;  // 後ろから見ていく
  int ans = 0;
  while(itr_front < itr_back) {
    // frontを見ていく
    while(itr_front < itr_back) {
      if(s[itr_front] == 'W') break;
      itr_front++;
    }
    // backを見ていく
    while(itr_back > itr_front) {
      if(s[itr_back] == 'R') break;
      itr_back--;
    }
    if(itr_front == itr_back) break;
    ans++;
    itr_front++;
    itr_back--;
  }
  cout << ans << endl;
}