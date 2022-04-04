#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
// const int INF = 1001001001;
const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

ll R, B, x, y;
// k個以上花束を作ることができるか？
bool check(ll k) {
  ll R2 = R-k;
  ll B2 = B-k;
  if(R2 < 0 || B2 < 0) return false;
  ll cnt = R2/(x-1) + B2/(y-1);
  return cnt >= k;
}

int main() {
  cin >> R >> B >> x >> y;
  ll ok = -1;
  ll ng = INF;
  while(ok+1 < ng) {
    ll mid = (ok+ng)/2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}