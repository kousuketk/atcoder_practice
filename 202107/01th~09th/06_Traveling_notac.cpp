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
  for(int i = 0; i < N; i++) {
    ll t, x, y; cin >> t >> x >> y;
    if(t < x || t < y || t < x+y) {
      cout << "No" << endl;
      return 0;
    }
    if(((x+y) % 2 == 0 && t % 2 == 1) || ((x+y) % 2 == 1 && t % 2 == 0)) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
// t1→t2と制限時間内に行けなければならない