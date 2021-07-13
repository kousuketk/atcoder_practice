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
  if(a+b <= 2*c) {
    cout << (a*x + b*y) << endl;
    return 0;
  }
  ll pay = 0;
  // min(x, y)*2をc円で買う
  pay += min(x, y)*2*c;
  if(x >= y) {
    int amount = x - min(x, y);
    // amount(余った量)について、a円, 2*c円を比較
    if(a <= 2*c) {
      pay += amount*a;
    } else {
      pay += amount*2*c;
    }
  } else {
    int amount = y - min(x, y);
    if(b <= 2*c) {
      pay += amount*b;
    } else {
      pay += amount*2*c;
    }
  }
  cout << pay << endl;
  return 0;
}