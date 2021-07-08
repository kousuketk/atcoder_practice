#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const ll INF = 100100100100100100100;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

ll R, B, x, y;

bool check(ll X) {
  ll R2 = R - X;
  ll B2 = B - X;
  if(R2 < 0 || B2 < 0) return false;
  ll amount = R2/(x-1) + B2/(y-1);
  return (amount >= X);
}

int main() {
  cin >> R >> B >> x >> y;
  ll left = 0;
  ll right = INF;
  while(left+1 < right) {
    ll mid = (left+right)/2;
    if(check(mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  cout << left << endl;
  return 0;
}
