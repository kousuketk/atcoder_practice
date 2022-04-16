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

int main() {
  int N; cin >> N;
  ll K; cin >> K;
  vector<int> vec(N);
  rep(i,N) {
    cin >> vec[i];
    vec[i]--;
  }
  int logK = 1;
  while((1LL<<logK) <= K) logK++;  // long longでやりたいときは1LLにする必要がある
  vector<vector<int>> doubling(logK+1, vector<int>(N));
  rep(i,N) doubling[0][i] = vec[i];
  for(int k = 1; k <= logK; k++) {
    rep(i,N) {
      doubling[k][i] = doubling[k-1][doubling[k-1][i]];
    }
  }
  int now = 0;
  for(int k = 0; K > 0; k++) {
    if(K & 1) now = doubling[k][now];
    K = K >> 1;
  }
  cout << now+1 << endl;
  return 0;
}