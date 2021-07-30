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

int N;
vector<T> vec;
int dp[(1<<18) + 1][18];

int rec(int bit, int v) {
  if(dp[bit][v] != -1) return dp[bit][v];
  if(bit == (1<<v)) {
    // 0, vのコストを出す(部分集合が最後の時)
    int tmp = abs(get<0>(vec[v])-get<0>(vec[0])) +
              abs(get<1>(vec[v])-get<1>(vec[0])) + 
              max(0, get<2>(vec[v])-get<2>(vec[0]));
    return dp[bit][v] = tmp;
  }
  
  int res = INF;
  int prev_bit = bit & ~(1<<v);

  for(int nv = 0; nv < N; nv++) {
    if(!(prev_bit & (1<<nv))) continue;
    // v, nvのコストを出す
    int tmp = abs(get<0>(vec[v])-get<0>(vec[nv])) +
              abs(get<1>(vec[v])-get<1>(vec[nv])) + 
              max(0, get<2>(vec[v])-get<2>(vec[nv]));
    res = min(res, rec(prev_bit, nv) + tmp);
  }

  return dp[bit][v] = res;
}

int main() {
  cin >> N;
  vec.resize(N);
  rep(i,N) {
    int x, y, z; cin >> x >> y >> z;
    vec[i] = T(x, y, z);
  }
  for(int bit = 0; bit < (1<<N); bit++) for(int v = 0; v < N; v++) dp[bit][v] = -1;
  cout << rec((1<<N)-1, 0) << endl;
}