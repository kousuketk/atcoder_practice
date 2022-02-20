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

bool dp[110][10100];
int main() {
  int max_x =10100;
  int N, X; cin >> N >> X;
  dp[0][0] = true;
  rep(i,N) {
    int a, b; cin >> a >> b;
    rep(j,max_x) {
      if(dp[i][j]) {
        dp[i+1][j+a] = true;
        dp[i+1][j+b] = true;
      }
    }
  }
  if(dp[N][X]) cout << "Yes" << endl;
  else cout << "No" << endl;
}