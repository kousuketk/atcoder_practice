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
  int N; cin >> N;
  ll ans = 0;
  for(int c = 1; c < N; c++) {
    int d = N-c;
    // dについてa, bの約数の数を数える
    for(int j = 1; j*j <= d; j++) {
      if(d % j == 0) {
        if(d/j != j) ans += 2;
        else ans++;
      }
    }
  }
  cout << ans << endl;
}