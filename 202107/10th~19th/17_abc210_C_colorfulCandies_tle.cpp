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
  int ans = 0;
  for(int i = 0; i < N-K+1; i++) {
    vector<int> vec_tmp(K);
    for(int j = 0; j < K; j++) {
      vec_tmp[j] = vec[i+j];
    }
    sort(vec_tmp.begin(), vec_tmp.end());
    vec_tmp.erase(unique(vec_tmp.begin(), vec_tmp.end()), vec_tmp.end());
    ans = max(ans, vec_tmp.length());
  }
  cout << ans << endl;
}