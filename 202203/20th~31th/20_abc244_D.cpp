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
  char s1, s2, s3; cin >> s1 >> s2 >> s3;
  char t1, t2, t3; cin >> t1 >> t2 >> t3;
  string ans;
  if(s1 == t1) {
    if(s2 == t2) ans = "Yes";
    else ans = "No";
  } else {
    // t1にあるものをs1にする
    if(s2 == t1) swap(s1, s2);
    else swap(s1, s3);
    // 判定
    if(s2 == t2) ans = "No";
    else ans = "Yes";
  }
  cout << ans << endl;
  return 0;
}