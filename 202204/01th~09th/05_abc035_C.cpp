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
  int N, Q; cin >> N >> Q;
  vector<pair<int, int>> inp(Q);
  rep(i,Q) {
    int l, r; cin >> l >> r;  // 区間[l,r)で考える
    l--;
    inp[i] = pair<int, int>(l, r);
  }
  vector<int> osero(N+1, 0);
  rep(i,Q) {
    int l = inp[i].first;
    int r = inp[i].second;
    osero[l]++;
    osero[r]--;
  }
  int sum = 0;
  rep(i,N) {
    sum += osero[i];
    osero[i] = sum;
  }
  string ans = "";
  rep(i,N) {
    if(osero[i] % 2 == 0) ans += "0";
    else ans += "1";
  }
  cout << ans << endl;
  return 0;
}