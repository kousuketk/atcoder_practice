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
void printVec(vector<int> &vec) {
  for (auto itr = vec.begin(); itr != vec.end(); itr++) cout << *itr << " "; 
  cout << endl;
}

int main() {
  int N; cin >> N;
  vector<int> vec1(N);
  vector<int> vec2(N);
  rep(i,N) cin >> vec1[i];
  rep(i,N) cin >> vec2[i];
  // 累積和を取っておく
  vector<int> S1(N+1);
  vector<int> S2(N+1);
  rep(i,N) S1[i+1] = S1[i] + vec1[i];
  rep(i,N) S2[i+1] = S2[i] + vec2[i];
  int ans = 0;
  for(int i = 0; i < N; i++) {
    // i番目の要素で下に行く
    // vec[0][0] ~ vec[0][i] + vec[1][i] ~ vec[1][N-1]
    int tmp = S1[i+1] + (S2[N] - S2[i]);
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}