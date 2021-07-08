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
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> B(n);
  rep(i,n) cin >> A.at(i) >> B.at(i);
  int ans = INF;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int a;
      if(i == j) a = A[i]+B[j];
      else a = max(A[i], B[j]);
      ans = min(ans, a);
    }
  }
  cout << ans << endl;
}