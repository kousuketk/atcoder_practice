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
  string s; cin >> s;
  vector<int> ans(N+1);
  int idx = 0;
  int idx_back = N;
  rep(i,N) {
    if(s[i] == 'L') {
      ans[idx_back] = i;
      idx_back--;
    } else {
      ans[idx] = i;
      idx++;
    }
  }
  ans[idx] = N;
  rep(i,N+1) cout << ans[i] << " ";
  cout << endl;
  return 0;
}