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
  vector<int> a(N/2);
  vector<int> b(N/2);
  if(N % 2 == 0) {
    rep(i,N) {
      if(i < N/2) cin >> a[i];
      else cin >> b[i - N/2];
    }
  } else {
    rep(i,N) {
      if(i == (N-1)/2) {
        int dump;
        cin >> dump;
        continue;
      }
      if(i < N/2) cin >> a[i];
      else cin >> b[i - (N+1)/2];
    }
  }
  reverse(b.begin(), b.end());
  set<int> S;
  for(int i = 0; i < N/2; i++) {
    if(a[i] != b[i]) {
      S.insert(a[i]);
      S.insert(b[i]);
    }
  }
  ll ans = 0;
  if(S.size() != 0) ans = S.size() - 1;
  cout << ans << endl;
}

// 連結成分(集合)が複数あるから、単純にset集合だと1つの集合に対してしか合っていない
// →UnionFindを使う