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

int N;

double dp[310][310][310];
double rec(int i, int j, int k) {
  if(dp[i][j][k] >= 0) return dp[i][j][k];
  if(i == 0 && j == 0 && k == 0) return 0.0;

  double res = 0.0;
  if(i > 0) res += rec(i-1, j, k) * i;
  if(j > 0) res += rec(i+1, j-1, k) * j;
  if(k > 0) res += rec(i, j+1, k-1) * k;
  res += N;
  res += 1.0/(i+j+k);

  return dp[i][j][k] = res;
}

int main() {
  cin >> N;
  int one = 0, two = 0, three = 0;
  for(int i = 0; i < N; i++) {
    int a; cin >> a;
    if(a == 1) one++;
    else if(a == 2) two++;
    else three++;
  }

  // 初期化
  memset(dp, -1, sizeof(dp));

  cout << fixed << setprecision(10) << rec(one, two, three) << endl;
}