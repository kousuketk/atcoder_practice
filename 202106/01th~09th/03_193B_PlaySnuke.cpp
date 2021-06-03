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
  int N;
  int ans = INF;
  cin >> N;
  for(int i = 0; i < N; i++) {
    int a, p, x;
    cin >> a >> p >> x;
    if(x-a > 0) {
      ans = min(ans, p);
    }
  }
  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;
}

