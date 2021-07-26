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

int main() {
  ll r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
  // 0回でいける
  if(r1==r2 && c1==c2) {
    cout << "0" << endl;
    return 0;
  }
  // 1回でいける
  if(
    r1+c1 == r2+c2 ||
    r1-c1 == r2-c2 ||
    (abs(r1-r2) + abs(c1-c2)) <= 3
  ) {
    cout << "1" << endl;
    return 0;
  }
  // 2回でいける
  if((abs(r1-r2) + abs(c1-c2)) <= 6) {
    cout << "2" << endl;
    return 0;
  }
  // 差が偶数だったら2回でいける
  if(abs(abs(r1-r2)-abs(c1-c2)) % 2 == 0) {
    cout << "2" << endl;
    return 0;
  }
  // 真上にもってくる 
  if(r1 != r2) {
    ll tmp_c2 = c2;
    if(c2 <= c1) tmp_c2 += abs(r2-r1);
    else tmp_c2 -= abs(r2-r1);
    ll tmp_r2 = r1;
    // そこから1回でいける
    if(
      r1+c1 == tmp_r2+tmp_c2 ||
      r1-c1 == tmp_r2-tmp_c2 ||
      (abs(r1-tmp_r2) + abs(c1-tmp_c2)) <= 3
    ) {
      cout << "2" << endl;
      return 0;
    }
  }
  // 真横にもってくる
  if(c1 != c2) {
    ll tmp_r2 = r2;
    if(r2 <= r1) tmp_r2 += abs(c2-c1);
    else tmp_r2 -= abs(c2-c1);
    ll tmp_c2 = c1;
    // そこから1回でいける
    if(
      r1+c1 == tmp_r2+tmp_c2 ||
      r1-c1 == tmp_r2-tmp_c2 ||
      (abs(r1-tmp_r2) + abs(c1-tmp_c2)) <= 3
    ) {
      cout << "2" << endl;
      return 0;
    }
  }
  cout << "3" << endl;
  return 0;
}