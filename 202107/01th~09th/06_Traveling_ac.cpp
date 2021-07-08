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
  ll t, x, y;
  ll before_t = 0, before_x = 0, before_y = 0;
  for(int i = 0; i < N; i++) {
    cin >> t >> x >> y;
    ll tmp_t = t - before_t;
    ll tmp_x = abs(x - before_x);
    ll tmp_y = abs(y - before_y);
    if(tmp_t < tmp_x+tmp_y) {
      cout << "No" << endl;
      return 0;
    }
    if(((tmp_x+tmp_y) % 2 == 0 && tmp_t % 2 == 1) || ((tmp_x+tmp_y) % 2 == 1 && tmp_t % 2 == 0)) {
      cout << "No" << endl;
      return 0;
    }
    before_t = t;
    before_x = x;
    before_y = y;
  }
  cout << "Yes" << endl;
}