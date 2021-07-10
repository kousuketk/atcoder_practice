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
  vector<int> vec(N);
  rep(i,N) cin >> vec[i];
  sort(vec.begin(), vec.end());
  int ans = 0;
  for(int i = 1; i < 100000; i++) {
    // lower_bound(i-1) - upper_bound(i+1)をすることで、
    int idx1 = lower_bound(ALL(vec), i-1) - vec.begin();
    int idx2 = upper_bound(ALL(vec), i+1) - vec.begin();
    ans = max(ans, idx2 - idx1);
  }
  cout << ans << endl;
}