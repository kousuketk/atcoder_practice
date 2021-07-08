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
  vector<int> vec(3*N);
  rep(i,3*N) cin >> vec[i];
  sort(vec.begin(), vec.end(), greater<int>{});
  ll ans = 0;
  for(int i = 0; i < N; i++) {
    ans += vec[i*2 + 1];
  }
  cout << ans << endl;
}