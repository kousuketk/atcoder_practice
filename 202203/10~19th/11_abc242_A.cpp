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
  double a, b, c, x; cin >> a >> b >> c >> x;
  double ans;
  if(x <= a) {
    ans = 1.000000000000;
  } else if(x > b) {
    ans = 0.0;
  } else {
    ans = c/(b-a);
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}