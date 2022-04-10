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
vector<int> next_h = {1, -1, 0, 0};
vector<int> next_w = {0, 0, 1, -1};

string dp[18];
string rec(int i) {
  if(dp[i] != "0") return dp[i];
  string res = rec(i-1) + " " + to_string(i) + " " + rec(i-1);
  return dp[i] = res;
}

int main() {
  int N; cin >> N;
  rep(i,18) dp[i] = "0";
  dp[1] = "1";
  string ans = rec(N);
  // auto itr = ans.begin();
  // while(itr != ans.end()) {
  //   if(itr != ans.begin()) cout << " ";
  //   cout << *itr;
  //   itr++;
  // }
  // cout << endl;
  cout << ans << endl;
  return 0;
}