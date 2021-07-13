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
  // 約数を出す計算量O(N)
  int ans = 0;
  for(int i = 1; i <= N; i += 2) {
    int tmp_count = 0;
    for(int j = 1; j <= i; j++) {
      if(i % j == 0) tmp_count++;
    }
    if(tmp_count == 8) ans++;
  }
  cout << ans << endl;
}