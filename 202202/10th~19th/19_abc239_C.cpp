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
vector<int> next_x = {2, 2, 1, 1, -1, -1, -2, -2};
vector<int> next_y = {1, -1, 2, -2, 2, -2, 1, -1};

int main() {
  ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  bool ans = false;
  rep(i,8) {
    ll x = x1 + next_x[i];
    ll y = y1 + next_y[i];
    // x, yとx2, y2の距離がルート5になればok
    ll dis = pow((x-x2), 2) + pow((y-y2), 2);
    if(dis == 5) ans = true;
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}