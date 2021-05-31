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
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  for(int i = 1; i < n+1; i++) {
    for(int j = 1; j < k+1; j++) {
      ans += i*100 + j;
    }
  }
  cout << ans << endl;
}