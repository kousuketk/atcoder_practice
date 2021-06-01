#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 10010010010;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int R, B, x, y;
  cin >> R >> B >> x >> y;
  int left = 0;
  int right = (R+B)/2 + 1;
  int mid = (left+right)/2;
  while(left+1 < right) {
    bool ok = false;
    int R2 = R - mid;
    int B2 = B - mid;
    int x2 = x - 1;
    int y2 = y - 1;
    if(R2 >= 0 && B2 >= 0) {
      int amount = R2/x2 + B2/y2;
      if(amount >= mid) ok = true;
    }
    // もし最大値がXより大きかったらok = true;
    if(ok) left = mid;
    else right = mid;
    mid = (left+right)/2;
  }
  cout << left << endl;
}

// https://atcoder.jp/contests/arc050/tasks/arc050_b
// boolの部分は関数で分けたほうがいい