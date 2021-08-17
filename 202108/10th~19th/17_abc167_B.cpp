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
  int a, b, c, k; cin >> a >> b >> c >> k;
  int ans = 0;
  if(k > 0) {
    int tmp = min(k, a);
    ans += tmp;
    k = k - a;
  }
  if(k > 0) {
    k = k - b;
  }
  if(k > 0) {
    int tmp = min(k, c);
    ans -= tmp;
    k = k-c;
  }
  cout << ans << endl;
}