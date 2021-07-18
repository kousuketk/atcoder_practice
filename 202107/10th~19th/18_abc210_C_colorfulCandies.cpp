#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
// const ll INF = 1100100100100100100;
const ll MOD = 1000000007;
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int N, K; cin >> N >> K;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  map<int, int> mp;
  int count = 0;
  int ans = 0;
  rep(i,N) {
    mp[vec[i]] += 1;
    if(mp[vec[i]] == 1) count++;
    // i-K番目を見ていく
    if(i-K >= 0) {
      mp[vec[i-K]] -= 1;
      if(mp[vec[i-K]] == 0) count--;
    }
    ans = max(ans, count);
  }
  cout << ans << endl;
}