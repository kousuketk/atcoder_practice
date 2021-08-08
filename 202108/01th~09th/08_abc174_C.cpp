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
  int K; cin >> K;
  // Kが偶数の時
  if(K % 2 == 0) {
    cout << -1 << endl;
    return 0;
  }
  int sum = 0;
  int ten = 1;
  int ans = -1;
  for(int i = 0; i <= 10000000; i++) {
    sum = (sum + 7*ten) % MOD;
    if(sum % K == 0 || sum+MOD % K == 0) {
      ans = i+1;
      break;
    }
    ten = ten*10 % MOD;
  }
  cout << ans << endl;
  return 0;
}