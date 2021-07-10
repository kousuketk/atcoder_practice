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
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  sort(vec.begin(), vec.end());
  ll ans = 1;
  for(int i = 0; i < N; i++) {
    // cout << vec[i]-i << endl;
    ans = (ans*(vec[i]-i)) % 1000000007;
  }
  cout << ans << endl;
}