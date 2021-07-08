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
  int N; cin >> N;
  vector<vector<int>> vec(N, vector<int>(3));
  rep(i,N) {
    ll x, y, h; cin >> x >> y >> h;
    vec[i][0] = x; vec[i][1] = y; vec[i][2] = h;
  }
  for(int a = 0; a <= 100; a++) {
    for(int b = 0; b <= 100; b++) {
      ll H = 0;
      bool flag = true;
      for(int k = 0; k < N; k++) {
        ll x, y, h;
        x = vec[k][0]; y = vec[k][1]; h = vec[k][2];
        if(h == 0) continue;
        H = h + abs(x-a) + abs(y-b);
        break;
      }
      for(int k = 0; k < N; k++) {
        ll x, y, h;
        x = vec[k][0]; y = vec[k][1]; h = vec[k][2];
        ll tmp_h = H - abs(x-a) - abs(y-b);
        if(tmp_h < 0) tmp_h = 0;
        if(h != tmp_h) flag = false;
      }
      if(flag) {
        cout << a << " " << b << " " << H << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}