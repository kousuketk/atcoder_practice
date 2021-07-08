#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
  // 全部2枚ペア
  int upper = max(x, y);
  ll pay0 = upper*c*2;
  int base = min(x, y);
  ll pay = 0;
  if(a+b >= c*2) {
    pay = base*2*c;
    x -= base; y -= base;
    if(x != 0) pay += x*a;
    if(y != 0) pay += y*b;
  } else {
    pay = x*a + y*b;
  }
  if(pay > pay0) cout << pay0 << endl;
  else cout << pay << endl;
}