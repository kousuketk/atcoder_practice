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
  vector<ll> vec(N);
  rep(i,N) cin >> vec[i];
  sort(vec.begin(), vec.end());
  ll ans = 0;
  for(int i = 0; i < N; i++) {
    int index = upper_bound(vec.begin(), vec.end(), vec[i]) - vec.begin();
    ans += N-index;
  }
  cout << ans << endl;
}