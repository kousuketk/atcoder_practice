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

vector<int> dp; 
int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    int a; cin >> a;
    auto itr = lower_bound(dp.begin(), dp.end(), a);
    if(itr == dp.end()) {
      dp.push_back(a);
    } else {
      *itr = a;
    }
  }
  cout << dp.size() << endl;
}
// dp[i]:長さがiであるような増加部分列における最終要素の最小値として扱っても良い
// // dp[i] = INF;
// for(int i = 0; i < N; i++) {
//   auto itr = lower_bound(ALL(dp), vec[i]);
//   *itr = vec[i];
// }
// // dp[i] != INFの最後のiを求めればいい
// auto itr = lower_bound(ALL(dp), INF);
// cout << itr - dp.begin() << endl;