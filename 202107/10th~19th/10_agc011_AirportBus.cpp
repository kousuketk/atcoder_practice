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
  int N, C, K; cin >> N >> C >> K;
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  sort(vec.begin(), vec.end());
  // for(int i = 0; i < N; i++) {
  int i = 0;
  int count = 0;
  while(i < N) {
    auto itr = upper_bound(vec.begin(), vec.end(), vec[i]+K);
    int idx = itr-vec.begin();
    int min_idx = min(idx-i, C);
    i += min_idx;
    count++;
  }
  cout << count << endl;
}