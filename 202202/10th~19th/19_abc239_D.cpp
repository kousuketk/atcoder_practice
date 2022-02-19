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
vector<int> sosu = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,139,149,151,157,163,167,173,179,181,191,193,197,199};

int main() {
  int a, b, c, d; cin >> a >> b >> c >> d;
  vector<bool> dp(300, false);
  rep(i,(int)sosu.size()) {
    int val = sosu[i];
    // val-c から val-dまでの範囲だと青木くんの勝ち
    int start = val-d;
    int end = val-c;
    if(start <= 0) start = 1;
    if(end <= 0) end = 1;
    for(int j = start; j <= end; j++) dp[j] = true;
  }
  // dpのa~bが全部trueだったら青木くんの勝ち, falseがあったら高橋くんの勝ち
  bool ans = true;  // 青木くんの勝ち
  for(int i = a; i <= b; i++) {
    if(!dp[i]) ans = false;
  }
  if(ans) cout << "Aoki" << endl;
  else cout << "Takahashi" << endl;
}